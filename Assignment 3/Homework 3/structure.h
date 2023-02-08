/** structure.h
 * @author Sean Arackal
 * Structer header function prototypes
*/
#ifndef STRUCTURE_H		// Remember guard
#define STRUCTURE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mystring.h"

typedef struct
{
  char* name; //a person's name
  int birth_year; //a person's birth birth_year
  int salary; // a person's salary
} Person;


// Function prototype(s):
Person* make_person(char* name, int birth_year, int salary);
void printPerson(Person *p);
char genRandomChar();
char* genRandomString(size_t size);
int genRandomInt(int min, int max);
Person* genRandomPerson();
Person** genRandomPersonArray(size_t n);
void printPersonArray(Person** personArray, size_t n);
Person** copyPersonArray(Person** source, size_t n);
void freePersonArray(Person** personArray, size_t n);



#endif
