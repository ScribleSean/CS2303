/** short program to demonstrate use of stack
 *
 * @author Blake Nelson
 */

#include <stdio.h>
#include "stack.h"

/** main function to demonstrate use of stack
 *
 */
int main (int argc, char *argv[]) {
  Stack *the_stack;
  char *test_data[] = {"first", "second", "third", "fourth", "fifth"};

  // Create a stack to hold our test data
  the_stack = create();
  #ifdef DEBUG_TEST
  printf ("sizeof(test_data)) == %ld\n", sizeof(test_data));
  #endif

  // Push some test data onto the stack
  for (int i = 0; i < (sizeof(test_data) / sizeof(char *)); i++) {
    #ifdef DEBUG_TEST
    printf("pushing element \"%s\"\n", test_data[i]);
    #endif
    push(the_stack, test_data[i]);
    #ifdef DEBUG_TEST
    printf("top of stack now \"%s\"\n", (char *) peek(the_stack));
    #endif
  }

  // Now pop the elements off the stack
  while (!isempty(the_stack)) {
    char *element = (char *) pop(the_stack);
    printf("popped element \"%s\"\n", element);
  }

  return 0;
}
