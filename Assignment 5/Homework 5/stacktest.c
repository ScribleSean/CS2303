/** stacktest.c
* short program to demonstrate use of stack
*
* @author Blake Nelson, Sean Arackal
*/

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "stack.h"

#define MAXLINE (4096)

/** main function to demonstrate use of stack
* @return 0 on success
* @return 1 on failure
*/
int main (int argc, char *argv[]) {

  if(argc!= 2)
  {
    printf("Enter exactly one argument on the command line!\n");
    return 1;
  }

  int user_size = atoi(argv[1]);

  if(user_size < 0)
  {
    printf("%d was entered but max elements must be greater than or equal to 0!\n",user_size);
    return 1;
  }

  Stack *the_stack;
  // Create a stack to hold our test data
  the_stack = create( user_size );

  if(the_stack == NULL)
  {
    printf("Not enough space to create stack!\n");
    return 1;
  }


  #ifdef DEBUG_TEST
  printf("Enter lines of strings into stack. Press CTRL+D to stop.\n");
  #endif

  ssize_t buff_size = MAXLINE; //max size of line in unix terminal
  char ** buffers = calloc(user_size, MAXLINE);


  if(buffers == NULL)
  {
    printf("Not enough space to create buffers array!\n");
    return 1;
  }


  size_t buff_idx; //loop counter


  for (buff_idx = 0;
    buff_idx < user_size &&
    getline(&buffers[buff_idx], &buff_size, stdin) != -1  ; buff_idx++)
  {

    #ifdef DEBUG_TEST
    printf("pushing element \"%s\"\n", buffers[buff_idx]);
    #endif

    push(the_stack, buffers[buff_idx]);

    #ifdef DEBUG_TEST
    printf("top of stack now \"%s\"\n", (char *) peek(the_stack));
    #endif
  }

  // Now pop the elements off the stack
  while (!isempty(the_stack))
  {

    char *element = (char *) pop(the_stack);

    #ifdef DEBUG_TEST
    printf("popped element \"%s\"\n", element);
    #endif

    printf("%s", element);
  }

  //free memory
  destroy(the_stack);
  free(buffers);

  return 0;
}
