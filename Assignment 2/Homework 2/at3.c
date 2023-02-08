/** file at.c
 * @Sean 
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include "print_arrays.h"
#include "array_sort.h"
#include <time.h>

#define SAMPLE_INT_ARRAY_SIZE (5)

/** Main program for demonstrating arrays. It fills them with random ints, sorts them and prints them.
 * @return 0, Indicating success.
 */

int main(int argc, const char* argv[])
{
  //change seed of random integers once per run of the program
  srand(time(NULL));

  if(argc!=3)
    {
      printf("Input only two numbers!\n");
      return 0;
    }

  int max = atoi(argv[1]);
  int array_size = (atoi (argv[2]));
  
  int a[array_size];
  
  fill_array_with_randoms(a, array_size, max);
  
  //Now print it out
  print_int_array(a, array_size);
  
  printf("\nNow printing sorted\n");
  
  bubble_sort_int(a, array_size);
  
  print_int_array(a, array_size);
  
  

}
