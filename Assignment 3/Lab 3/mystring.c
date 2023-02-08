/** mystring.c
 * @author Mike Ciaraldi, Blake Nelson
 * Custom versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; 	// Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  		// Leave space for the terminator
  newstr = (char*) malloc(length); 	// Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) {
	return (char *) 0;
  }

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/** Returns the length of a C-style string
 @param src Pointer to string of which the length we need to calculate
 @return integer value of the length of the string
*/

int mystrlen(const char* src) {
  int size=0;
  char aChar= *src;
  while(aChar != '\0'){
    size++;
    aChar = *(++src);
  }
  return size;
}

/** Copies a C-style string
 @param cpy  Pointer to string that gets copied
 @param src Pointer to new copy of string
 @return pointer to the new copy of string
*/

char* mystrcpy(char *cpy, const char *src) {
  char* cpyChar = cpy;
  while(*src != '\0'){
    *cpy = *src;
    src++;
    cpy++;
  }
  *cpy = *src; //for null
  return cpyChar;
}
