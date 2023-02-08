/** file print_arrays.c
 * @author 
 *
 * Functions for printing arrays.
 */

#include <stdio.h>
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

void print_double_array(double a[], int num_entries) {
	// TODO: Fill in with code.
}

