/** sorttest2.c
 * @author Sean Arackal
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include "sort.h"
#include "string.h"

/* Program which inputs a number and then generates and processes a much larger set of integers.
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest2 some_number sort_type
 * Example:
 *         ./sorttest2 2413 alt_sort_descending
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {

  int *nums; // space to store numbers entered from the command line.

  int next_num; // Integer read from the command line goes here.
  int i; // array index
  int length; // size of array
  int sort_type=-1;

  if(argc!=3)
  {
    printf("Must enter exactly two arguments on the command line! \n");
    return 1;
  }

  length = atoi(argv[1]);

  if(strcmp(argv[2], "sort_descending")==0)
  {
    sort_type=0;
  }
  else if(strcmp(argv[2], "alt_sort_descending")==0)
  {
    sort_type=1;
  }
  else
  {
    printf("Enter only \"sort_descending\" or \"alt_sort_descending\" after the first argument on the command line!");
    return 1;
  }


  nums = (int*) calloc(length, sizeof(int));

  if (nums == NULL)
  {
    fprintf(stderr, "Unable to allocate enough memory to hold the numbers.\n");
    return 1;
  }

  genRandomArray(nums, length, RAND_MAX);

  timesort(nums, length, sort_type);

  return 0; // Indicate success!
}
