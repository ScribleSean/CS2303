/** Program demonstrating parsing and linked lists. This program
 * supports zip code lookup for any town in Massachusetts
 *
 * @author Blake Nelson, Sean Arackal
 *
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <string>
 #include <forward_list>
 #include <readline/readline.h>
 #include <readline/history.h>
 #include <vector>
 #include <iostream>
 #include "zipfed.hpp"
//#include "zipfilter.h"

// size of fully qualified path/file name with null terminator
#define SZ_FILENAME (129)

//max size of input line buffer
#define MAXLINE (4096)


/** Function to read a line from the fed2cs2303 zip and return pointer to it
* @param lineptr pointer to the dynamically allocated buffer
* @param n pointer to the size of the buffer pointer
* @param the FILE pointer to the open file to read.
* @return read_byte_count number bytes (chars) read
*/
ssize_t readln_fedcs2303(char **lineptr, size_t *n, FILE *stream)
{
  ssize_t read_byte_count = -1;
  const int delim = '\n';

  if (stream == NULL)
  {
    return (ssize_t) -1;
  }
  read_byte_count = getdelim (lineptr, n, delim, stream);
  for (int i = read_byte_count - 1; i >= 0; i--)
  {
    if ((*lineptr)[i] == '\n')
    {
      (*lineptr)[i] = '\0';
    }
  }

  return read_byte_count;

}

/** comparer for forward list based on zipfed city attr.
 *  @param zipfed_ptr1 pointer to first zipfed
 *  @param zipfed_ptr2  pointer to second zipfed
 *  @return boolean
 */

bool comparator_function(Zipfed* zipfed_ptr1, Zipfed* zipfed_ptr2)
{
  return zipfed_ptr1->get_city().compare(zipfed_ptr2->get_city()) < 0;
}

/** program to find the zip code for any town in Massachusetts
 *
 * @param argc is the number of field on command line - should be 1
 * @param argv is array of strings entered on command line - prog name
 * @return 0 for success
 * @return other for failure
 */

int main (int argc, char *argv[])
{
   char infile[SZ_FILENAME];
   FILE *fdIn;

   ssize_t chars_read;        // number of chars of input
   char *inbuf = NULL;        // buffer
   size_t sz_inbuf = 0;       //  ize of the input record

   std::forward_list<Zipfed *> llist; // inked list of pointers to Zipfed instances

   if (argc != 2)
   {
     fprintf(stderr, "usage: %s input_file\n", argv[0]);
     return -1;
  }

  strncpy(infile, argv[1], SZ_FILENAME-1);

  fdIn = fopen(infile, "r");

  if (fdIn == NULL)
  {
    fprintf(stderr, "cannot open %s for input - exiting\n", infile);
    return -2;
  }

  std::vector<std::string> queries;

  char * buffer = (char *) calloc(1, MAXLINE);

  printf("Enter city names line by line: (CTRL+D to stop)\n");

  size_t buff_idx; // loop counter

  for(buff_idx = 0; (buffer = readline("_ ")) != NULL ; buff_idx++)
  {
    queries.push_back(buffer); // push to vector
  }

  printf("\n");

  // loop to go through each line of zipcode data
  while ((chars_read = readln_fedcs2303(&inbuf, &sz_inbuf, fdIn)) != EOF)
  {
    if (chars_read == 0)
    {
      continue;
    }
     #ifdef DEBUG
     printf("inbuf: %s\n", inbuf);
     #endif

     Zipfed *pZipfed = new Zipfed();
     if(pZipfed->parse_zip_cs2303(inbuf) != 0)
     {
       fprintf (stderr, "failed to process input record - exiting\n");
       fclose (fdIn);
       return -4;
     }

      if(pZipfed->is_from(queries))
      {
        llist.push_front(pZipfed);
      }
  }

  llist.sort(comparator_function); // alphabetical sort

  printf("All items from %s were processed successfully!\n\n", infile);

  for(std::forward_list<Zipfed *>::iterator it = llist.begin(); it != llist.end(); it++)
  {
    Zipfed * pTmpZipfed = *it;
    pTmpZipfed->print();
  }

  while (!llist.empty()) // freeing memory
  {
    llist.pop_front();
  }

  free(buffer);

  return 0;
}
