/** Program to read in public zip code information and store as needed
 * for cs2301 assignment needs.
 *
 * @author Blake Nelson, Sean Arackal
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <forward_list>
#include "zipfed.hpp"

// size of fully qualified path/file name with null terminator
#define SZ_FILENAME (129)

/** Function to read a line from the US FED and return pointer to the
 * line of data represented as a C-String (i.e. NULL terminated string)
 *
 * @lineptr is a pointer to the dynamically allocated buffer to fill.
 *   If the pointer is NULL, a buffer will be allocated to hold the line.
 *   If the buffer is too small to hold the line, realloc will be called
 *   to allocate a larger buffer. If the buffer is reallocated, n will
 *   be set to new size.
 * @n is a pointer to the size of the buffer pointer to be lineptr. If
 *   memory is reallocated for lineptr, the size of n will be incremented
 *   accordingly. The parameter n will always specify the size of buffer
 *   pointed at by lineptr.
 * @fptr is the FILE pointer to the open file to read.
 * @return number bytes (chars) read or -1 on error
 */
ssize_t readln_fed (char **lineptr, size_t *n, FILE *stream) {
  ssize_t bytes_read = -1;  // -1 will signify error reading line
  const int delim = '\n';   // each line terminated with \r\n

  // Verify the file is open
  if (stream == NULL) {
    return (ssize_t) -1;
  }

  // Each line of the FED ZIP CSV file is terminated by \n\r, so we
  // read up to and including the \r for the entire line
  bytes_read = getdelim (lineptr, n, delim, stream);

  // Remove the \n\r at the end of the line by replacing with NULL terminator
  // Expect length of at least 2 for the \n\r at end of a line
  for (int i = bytes_read - 1; i >= 0; i--) {
    if (((*lineptr)[i] == '\n') || ((*lineptr)[i] == '\r')) {
      (*lineptr)[i] = '\0';
    }
  }

  return bytes_read;
}

/** main function to drive program. Input and output file names specified
 * on command line.
 *
 * usage:
 *    fed2cs2301 input_file output_file
 *
 * The input file must already exist. Output file will be created.
 *
 * Approach:
 * 1) Open both input and output files, or fail with error
 * 2) Read a line from input. This is a record of federal zip code data
 *    Note: the first line of the file is header info, not data, ignore it
 * 3) Parse the input line to populate a ZIP_FEDERAL structure
 * 4) Write the ZIP_FEDERAL structure to output file 1 record / line
 *    Note: no column header information will be written out, just  data fields
 * 5) Close output and input files and exit cleanly
 *
 * @param argc is the number of input strings - will be 3
 * @param argv is array of cmd line args -
 *        fed2cs2301 existing_input_file output_file_to_create
 * @return 0 for success. non-zero for error
 */
int main (int argc, char *argv[]) {
  char infile[SZ_FILENAME];  // Path/name of input file
  char outfile[SZ_FILENAME]; // Path/name of output file
  FILE *fdIn;
  FILE *fdOut;

  ssize_t chars_read;        // number of chars read for line of input
  char *inbuf = NULL;        // input file has 1 record per line to buffer
  size_t sz_inbuf = 0;       // current size of the input record

  std::forward_list<Zipfed *> llist; // singly linked list of pointers to Zipfed instances

  /* Open input and output files specified on command line
   * Common sense error checking on cmd line parameters
   */
  if (argc != 3) {
    fprintf(stderr, "usage: %s input_file output_file\n", argv[0]);
    return -1;
  }

  strncpy(infile, argv[1], SZ_FILENAME-1);
  strncpy(outfile, argv[2], SZ_FILENAME-1);

  /* Open input and output files - return error on failure
   * input for reading. output for writing
   */
  fdIn = fopen(infile, "r");
  if (fdIn == NULL) {
    fprintf(stderr, "cannot open %s for input - exiting\n", infile);
    return -2;
  }
  fdOut = fopen(outfile, "w");
  if (fdOut == NULL) {
    fprintf(stderr, "cannot open %s for output - exiting\n", outfile);
    fclose(fdIn);
    return -3;
  }

  /* Now a loop to read each line of the input file formatted and structured
   * as downloaded from US Government. Then, each line is loaded into our
   * zip code data structure before writing it out to the output file.
   *
   * Notes:
   *  - each line of the input is a zip code record.
   *    the first line of the input is column hedaders, not data. skip it.
   *  - each record will be written to ouput on its own line
   *  - read until EOF on input or error either reading or writing
   */
  // Just read and discard first line of input, it's column names
  chars_read = readln_fed (&inbuf, &sz_inbuf, fdIn);

  // Now loop to process each line of zip code data in CSV format
  while ((chars_read = readln_fed (&inbuf, &sz_inbuf, fdIn)) != EOF) {
    if (chars_read == 0) {  // not EOF, but nothing to process
      continue;
    }

    // write the buffer to stdout for debugging
#ifdef DEBUG
    printf("inbuf: %s\n", inbuf);
#endif

    // for each input line we create a new object instance of Zipfed, have the object
    // parse the input record and initialize itself with the parse result
    // Nonzero return indicates error parsing
    Zipfed *pZipfed = new Zipfed();
    if(pZipfed->parse_zip_federal(inbuf) != 0) {
      fprintf (stderr, "failed to process input record - exiting\n");
      fclose (fdIn);
      fclose(fdOut);
      return -4;
    }

    // write the structure to stdout to verify processing during development
    /* printf ("DEBUG: "); */
    /* pZipfed->print(); */

    // Add the zip code record into the linked list
    if(pZipfed->is_from_MA())
    {
      llist.push_front(pZipfed);
    }
  }

  // Now iterate through the list to make sure it's all there
  // zipprint will print the struct to output stream
  for(std::forward_list<Zipfed *>::iterator it = llist.begin(); it != llist.end(); it++) {
    Zipfed * pTmpZipfed = *it;
    pTmpZipfed->print(fdOut);
  }


  /* Free memory before exiting
   * keep deleting the head until list is empty.
   * this code is responsible for freeing the zip code data struct
   * the linked list will free the node form the linked list
   */
  while (!llist.empty()) {
    llist.pop_front();
  }

  return 0;
}
