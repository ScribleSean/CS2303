/** Short program to total numbers from 0 to specified value (inclusive)
 *
 * @author Mike Ciaraldi, Blake Nelson
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Totals all the integers from 0 to n.
 * @param n Value to total up to.
 * @return The total
 */

int sum(int n) {
  int i;                        // Simple loop counter
  int total = 0;                // Total accumulates here

  // Loop for every i, 0 through n, inclusive.
  for (i = 0; i <= n; i++) { 
    total += i; 
  }

  return total;  
}

/** Program to sum consecutive integers.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to these words, as character strings.
 *    The first word after the program name is the number to sum up to.
 */

int main(int argc, char* argv[]) {
  int n;
  int tot;

  printf("Starting program dtest.\n");
  
  if (argc < 2) {
    fprintf(stderr,"Must enter one number on the command line.\n");
    return 1;
  }
  
  n = atoi(argv[1]);
  tot = sum(n);

  printf("Sum of 0 through %d is %d\n", n, tot);
  
  printf("Ending program dtest.\n"); 
  return 0;
}
