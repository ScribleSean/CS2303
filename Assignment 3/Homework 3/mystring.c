/** mystring.c
 * @author Sean Arackal, Mike Ciaraldi, Blake Nelson
 * Custom versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param source Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of source
         or null if no memory is available
*/
char* mystrdup(const char* source)
{
  int length; 	// Length of the source string
  char* target; // Pointer to memory which will hold new string

  length = mystrlen(source) + 1;  		// Leave space for the terminator
  target = (char*) malloc(length); 	// Must cast!

  // If no memory was available, return null pointer immediately
  if (target == 0) {
	return (char *) 0;
  }

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(target, source);
  return target;
}

/** Duplicates a C-style string up to n characters.
 @param source Pointer to string to be duped
 @param n the number of characters to be duped from source
 @return Pointer to freshly-allocated string containing a duplicate of source
         or null if no memory is available
*/
char* mystrndup(const char* source, size_t n)
{
  int size = mystrlen(source)+1;
  char* targetChar = (char*) malloc(size);

  if(targetChar ==0)
  {
    return (char*) 0; //returns null pointer if no memory
  }

  mystrncpy(targetChar, source, n);
  *(targetChar+size) = '\0';
  return targetChar;
}

/** Returns the length of a C-style string
 @param source Pointer to string of which the length we need to calculate
 @return integer value of the length of the string
*/

size_t mystrlen(const char* source)
{
  int size=0;
  char aChar= *source;
  while(aChar != '\0') //go through the string until you reach the null character at the end
  {
    size++; // value of size increases for each character
    aChar = *(++source);
  }
  return size;
}

/** Copies a C-style string
 @param cpy  Pointer to string that gets copied
 @param source Pointer to new copy of string
 @return pointer to the new copy of string
*/

char* mystrcpy(char *cpy, const char *source)
{
  char* cpyChar = cpy;
  while(*source != '\0')
  {
    *cpy = *source;
    source++;
    cpy++;
  }
  *cpy = *source; //for null
  return cpyChar;
}

/** Copies the first n bytes of source.
 @param cpy  Pointer to string that gets copied
 @param source Pointer to new copy of string
 @param n number of bytes
 @return pointer to the new copy of string
*/

char* mystrncpy(char* cpy, const char* source, size_t n)
{
  char* cpyChar = cpy;
  int size = mystrlen(source);

  for(int i = 0; i<n ; i++)
  {
    if(i > size)
    {
      *cpy = '\0';
      cpy++;
    }
    else
    {
      *cpy = *source;
      cpy++;
      source++;
    }
  }
  return cpyChar;
}


/** Concatenates two string to each other
 @param target  Pointer to first part of the string which is also the final concatenation
 @param source Pointer to the string to be concatenated to the first string
 @return pointer to the concatenated string
*/

char* mystrcat(char *target, const char *source)
{
  int size =  mystrlen(target);
  char* targetChar = target; // storing the location of the first char
  char* pointOfCat = target+size; //pointer to the position where two strings meet

  while(*source != '\0')
  {
    *pointOfCat = *source;
    pointOfCat++;
    source++;
  }

  *pointOfCat = *source; //for null
  return targetChar;

}

/** Concatenates two string to each other from n chars into source
 @param target  Pointer to first part of the string which is also the final concatenation
 @param source Pointer to the string to be concatenated to the first string
 @param n the number of characters to concatenate from source to targe
 @return pointer to the concatenated string
*/

char* mystrncat(char* target, const char* source, size_t n)
{
  int size =  mystrlen(target);
  char* targetChar = target; // storing the location of the first char
  char* pointOfCat = target+size; //pointer to the position where two strings meet

  for(int i = 0; i<n; i++)
  {
    if(i > size)
    {
      break;
    }
    *pointOfCat = *source;
    pointOfCat++;
    source++;
  }
  return targetChar;
}
