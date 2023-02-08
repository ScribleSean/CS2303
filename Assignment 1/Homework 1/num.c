#include <stdio.h>
#include <stdlib.h>


/* Very simple program to demo reading a number from the command line.
 * Created by Sean Arackal, sarackal
 * 
 * Usage:
 *   ./num some_number
 * Example:
 *   ./num 2303
 * 
 */

int main (int argc, const char* argv[])
{
  int n; //integer read from the command line goes here

  if(argc<2) //check that there was an entry
    {
      printf("Must enter a number on the command line!\n");
      return 1; //indicate failure
    }

  n = atoi(argv[1]); //get string from command line, convert to int
  printf("The number you entered was: %d\n",n);
  return 0; //indicate success
}
