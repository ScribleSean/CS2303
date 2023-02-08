/** structure.c
 * @author Sean Arackal
 * class for creating structures
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mystring.h"
#include "structure.h"


/** creates a persons struct
 * @param name The name of the person in string
 * @param birth_year The birth year of the person
 * @param salary The salary of the person in int
 * @return pointer to person struct
 */
Person* make_person(char* name, int birth_year, int salary)
 {
	Person *p = (Person *)malloc(sizeof(Person));
  p->name = mystrndup(name, mystrlen(name));
	p->birth_year = birth_year;
	p->salary = salary;
	return p;
}

/**
 * prints the properties of a person
 * @param p the person structure
 */
void printPerson(Person *p)
{
  printf("Name is %s\n", p->name);
	printf("Birth year is %d\n",p->birth_year);
	printf("Salary is %d\n", p->salary);
}

/** generates a random character
 @return a random char
*/

char genRandomChar()
{
  double randChar = (double)rand()/RAND_MAX;
  return (char)(26*randChar+65);
}


/** generates a random string
 @param size for the lenght of the random string
 @return a pointer to the random string
*/
char* genRandomString(size_t size)
{
  char* genString = (char *)malloc(size+1);
  size_t i;
  for(i = 0; i<size; i++)
  {
    *(genString + i) = genRandomChar();
  }

  *(genString + size) = '\0';
  return genString;
}


/** generates a random integer
 @param min for the lowest possible value
 @param max for the max possible value
 @return a random int
*/
int genRandomInt(int min, int max)
{
  double randInt = (double)rand()/RAND_MAX;
  return(max-min+1)*randInt+min;
}

/** generates a random struct of person type
 @return a pointer to the random person
*/

Person* genRandomPerson()
{
  Person* randomPerson = (Person *)malloc(sizeof(Person));
  char* randomName = genRandomString(10);
  randomPerson->name = mystrndup(randomName, mystrlen(randomName));
  randomPerson->birth_year = (int)genRandomInt(1582, 2023);
  randomPerson->salary = (int)genRandomInt(0, 200000);
  return randomPerson;
}

/** generates a random array of structs of person type
 @param number of random persons
 @return a pointer to the random array
*/

Person** genRandomPersonArray(size_t n)
{
  Person** randPersonArray = (Person **)malloc(n * sizeof(Person*));
  size_t i;
  for (i = 0; i < n; i++)
  {
    randPersonArray[i] = genRandomPerson();
  }
  return randPersonArray;
}

/** prints a array of structs of person type
 @param personArray of random persons
 @param n number of persons
*/
void printPersonArray(Person** personArray, size_t n)
{
  for(int i = 0; i < n; i++)
  {
    printPerson(personArray[i]);
  }
}

/** shallow copy an array of persons
 * @param source The source array.
 * @param n A count of the elements in the array.
 * @return pointer to copied array
 */
Person** copyPersonArray(Person** source, size_t n)
{
    Person** personArray = (Person **)malloc(n * sizeof(Person**));
    for (size_t i = 0; i < n; i++)
    {
        personArray[i] = source[i];
    }
    return personArray;
}

/** frees an array of persons and frees the pointers
 * @param personArray the array to free
 * @param n  tne number of persons
 */
void freePersonArray(Person** personArray, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(personArray[i]);
        personArray[i] = NULL;
    }
}
