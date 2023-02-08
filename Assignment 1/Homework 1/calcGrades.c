#include "calcGrades.h"
#include <stdio.h>


/* Seperate source file with a function for grades.c
 * Created by Sean Arackal, sarackal
 */

int calcGrades(int numOfInts, int grades[])
{
  int i; //loop counter
  double gpa = 0;//variable to store gpa
  int highestGrade=0;//variable to store the highest grade (biggest number from all inputs)
  int lowestGrade=100;//variable to store the lowest grade (smallest number from all inputs)
  for(i = 0; i<numOfInts; i++)
    {
      (grades[i] < lowestGrade) ? lowestGrade = grades[i] : 1; //swap lowestGrade as we go through the array
      (grades[i] > highestGrade) ? highestGrade = grades [i] : 1; //swap highestGrade as we go through the array
      gpa += grades[i];
    }
  gpa = (double)gpa/(double)numOfInts; //gpa calculated as average of all inputted grades
  printf("The lowest grade was: %d\n", lowestGrade);
  printf("The highest grade was: %d\n",highestGrade);
  printf("Cumulative GPA from the given grades is: %f\n",gpa);
  
  return 0;
}


