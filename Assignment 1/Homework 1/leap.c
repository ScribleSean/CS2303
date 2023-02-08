#include <stdio.h>
#include <stdlib.h>


/* Simple program to check if inputted number is a leap year or not
 * Created by Sean Arackal, sarackal
 * 
 * Usage:
 *   ./leap a_number
 * Example:
 *   ./leapS 2303
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

  n = atoi(argv[1]); //n takes the number given 

  if(n < 1752) //error case for inputs less than 1752. 
    {
      printf("Cannot check check the year %d as we can only check for years after 1752\n",n);
    }

  else if(n % 4 == 0)//first check for leap years
    {
      if(n % 100 == 0) //second check for the 1800,1900,2000 cases
	{
	  if(n % 400 == 0)//third check to remove 1900 from 2000 cases
	    {
	      printf("The year %d is a leap year!\n",n);
	    }
	  else
	    {
	      printf("The year %d is not a leap year \n",n);
	    }
	}
      else //for cases that aren't centuries but leap years
	{
	  printf("The year %d is a leap year!\n",n);
	}
    }
    
  else //all non leap years
    {
      printf("The year %d is not a leap year \n",n);
    }
  return 0; //indicate success   
}
