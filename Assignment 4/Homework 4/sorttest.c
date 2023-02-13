/** sorttest.c
 * file that makes and sorts an array from the command line
 * @author Sean Arackal
 */
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Program which reads numbers from the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest some_number another_number ...
 * Example:
 *         ./sorttest 2014 15 7000
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
  int num_nums; // How many numbers actually entered on the command line.

  // Check that there are at least two numbers
  num_nums = argc - 1;
  if (num_nums < 2) {
    printf("Must enter at least 2 numbers on the command line! Exiting.\n");
    return 1; // Indicate failure
  }

  // Allocate an array big enough to hold the numbers
  nums = (int*) calloc(num_nums, sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Unable to allocate enougn memory to hold the numbers.\n");
  }

  /* Read all the numbers from the command line and put them into the array */
  for (i = 0; i < num_nums; i++) {
    next_num = atoi(argv[i+1]); // Get string from command line; convert to int
    nums[i] = next_num; // store into the array
  }

  // Now print, sort, and print the array, and time how long the sorting took.
  timesort(nums, num_nums,0);

  return 0; // Indicate success!
}
