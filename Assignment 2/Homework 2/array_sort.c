/** file array_sort.c
 * @Sean 
 *
 * Functions for sorting arrays.
 */

#include <stdio.h>
#include <stdlib.h>
#include "array_sort.h"

/** Sorts an array of doubles into ascending order by bubble sort
    @param The Array to sort
    @param array_size The size of the array
*/

void bubble_sort(double a[], int array_size)
{
  int i,j;
  double k;

  for(i=0; i < array_size; i++)
    {
      for(j=0; j < array_size; j++)
	{
	  if(a[i] < a[j])
	    {
	      k = a[i];
	      a[i]=a[j];
	      a[j]=k;
	    }
	}
    }
}

void bubble_sort_int(int a[], int array_size)
{
  int i,j;
  double k;

  for(i=0; i < array_size; i++)
    {
      for(j=0; j < array_size; j++)
	{
	  if(a[i] < a[j])
	    {
	      k = a[i];
	      a[i]=a[j];
	      a[j]=k;
	    }
	}
    }
}

/** Generates a random integer
    @param The maximum value of the random integer to be generated
    @return the randomly genereated integer
*/

int generate_random_int(int max)
{
  int random_num;
  random_num  = (rand() % (max + 1)); // generate random int between 0 and max inclusive
  return random_num;
}

/** Fills an array with random integers
    @param The Array to fill
    @param array_size The size of the array
    @param the maximum possible value of each integer in the array
*/

void fill_array_with_randoms(int a[], int array_size, int max)
{
  for(int i = 0; i < array_size ; i++)
  {
  a[i] = generate_random_int(max);
  }
}


