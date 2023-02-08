/** mystring.h
 * @author Mike Ciaraldi, Blake Nelson
 * My own versions of some of the C-style string functions
*/
#ifndef MYSTRING_H		// Remember guard
#define MYSTRING_H

// Function prototype(s):
char* mystrdup(const char* source);
char* mystrndup(const char* source, size_t n);

size_t mystrlen(const char* source);

char* mystrcpy(char* cpy, const char* source);
char* mystrncpy(char* cpy, const char* source, size_t n);

char* mystrcat(char* target, const char* source);
char* mystrncat(char* target, const char* source, size_t n);
#endif
