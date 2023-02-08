#include "calcGrades.h"
#include <stdio.h>
#include <stdlib.h>


/* Very simple program to calculate the gpa from a list of inputted numbers.
 * Created by Sean Arackal, sarackal
 * 
 * Usage:
 *   ./grades a_list_of_numbers
 * Example:
 *   ./grades 1 4 3
 * 
 */

#define MAX_GRADES (20)

int main (int argc, const char* argv[])
{
  int n; //integer read from the command line goes here

  if(argc<2) //check that there was an entry
    {
      printf("Enter one or more grades on the command line!\n");
      return 1; //indicate failure
    }
  else if(argc -1 > MAX_GRADES) //when the number of inputs excees MAX_GRADES
    {
      printf("Too many inputs. Removing extra inputs.\n");
    }

  int grades[MAX_GRADES]; //array for the grades inputted
  int numberOfGrades = (argc-1 > MAX_GRADES) ? MAX_GRADES : argc-1; //giving the numberOfGrades a value. Either the number of grades inputted or MAX_Grades if too many inputs.
  printf("Grades entered: %d\n", numberOfGrades);

  int i; //loop iteration counter
  for(i = 1; i<= numberOfGrades; i++)
    {
      grades[i-1] = atoi(argv[i]); //store grade in array
      printf("Grade: %d\n", grades [i-1]);
    }

  n = atoi(argv[1]); //get string from command line, convert to int
  return calcGrades(numberOfGrades, grades); //indicate success
}
