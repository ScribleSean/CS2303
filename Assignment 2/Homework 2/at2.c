/** file at.c
 * @Sean 
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include "print_arrays.h"
#include "array_sort.h"

#define SAMPLE_INT_ARRAY_SIZE (10)

/** Main program for demonstrating arrays. It fills them, sorts them and prints them.
 * @return 0, Indicating success.
 */

int main(int argc, const char* argv[]) {

  double a[SAMPLE_INT_ARRAY_SIZE]; // Sample array for demonstration
  int array_size = input_double_array(argc, argv, a, SAMPLE_INT_ARRAY_SIZE);
  
  printf("\nPrinting entered array\n"); 

  // Now print it out
  print_double_array(a, SAMPLE_INT_ARRAY_SIZE);

  //Now sort the array
  bubble_sort(a, SAMPLE_INT_ARRAY_SIZE);
  
  printf("\nPrinting sorted array\n");

  //Now print it out
  print_double_array(a, SAMPLE_INT_ARRAY_SIZE);

  return 0; // Success!
}
