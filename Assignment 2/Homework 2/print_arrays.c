/** file print_arrays.c
 * @Sean 
 *
 * Functions for printing arrays.
 */

#include <stdio.h>
#include <stdlib.h>
#include "print_arrays.h"

/** Print an array of ints, one per line.
    @param a Array to print
    @param num_entries Number of entries in the array
*/

void print_int_array(int a[], int num_entries) {
  int i; // Loop counter

  for (i = 0; i < num_entries; i++) {
    printf("%d\n", a[i]);
  }
}

/** Print an array of doubles, one per line.
    @param a Array to print
    @param num_entries Number of entries in the array
*/

void print_double_array(double a[], int num_entries) {
  int i; // Loop counter

  for(i = 0; i < num_entries; i++)
    {
      printf("%f\n",a[i]);
    }
}


/** Storing double floating-point values from the command line into an array
    @param argc Number of command line arguments
    @param argv Array of command line inputs
    @param a The array that will store the inputs
    @param num_entries Number of elements in the array
    @return The size of the array or the number of num_entries processed
*/


int input_double_array(int argc, const char* argv[], double a[], int num_entries)
{
  int num_of_elements = 0;
  for(int i =0; i < num_entries; i++)
    {
      if(argc<2) //check that there was an entry
	{
	  printf("Enter one or more grades on the command line!\nPrinting empty array!\n");
	  return 1; //indicate failure
	}
	
	if((i+1)>(argc-1))
	{
	  num_of_elements = num_entries;
	  printf("Not enough inputs! Filling extra array spaces with 0.\n"); //when the number of inputs is less than array size
	  break;
	}
	
	if((argc-1)<(i-1))
	{
	  num_of_elements = num_entries;
	  printf("Too many inputs! Removing extra inputs!\n"); //when the number of inputs is more than array size
	}
	
      a[i] = atof(argv[i+1]);
      num_of_elements+=1;
    }
  return num_of_elements;
}


