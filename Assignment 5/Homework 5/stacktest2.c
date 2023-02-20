/** stacktest2.c
* reverse the order of characters in a string using a stack
* @author Sean Arackal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "stack.h"

#define MAXLINE (4096)

/** main function to demonstrate use of stack
* @return 0 on success
* @return 1 on failure
*/
int main (int argc, char *argv[])
{

  if(argc!= 2)
  {
    printf("Enter exactly one argument on the command line!\n");
    return 1;
  }

  int user_size = atoi(argv[1]);

  if(user_size<0)
  {
    printf("%d was entered but max elements must be greater than or equal to 0!\n",user_size);
    return 1;
  }

  Stack *main_stack;
  // Create a stack to hold our test data
  main_stack = create(user_size);

  if(main_stack == NULL)
  {
    printf("Not enough space to create stack!\n");
    return 1;
  }


  #ifdef DEBUG_TEST
  printf ("Enter lines of strings into stack. Ctrl + D to stop.\n");
  #endif

  ssize_t buff_size = MAXLINE; //max size of line in unix terminal
  char ** buffers = calloc(user_size, buff_size);

  if(buffers == NULL)
  {
    printf("Not enough space to create buffers array.\n");
    return 1;
  }


  size_t buff_counter; //loop counter
  ssize_t buff_linesize; //contains actual line size of each line

  Stack *sub_stack[user_size];


  // Push some test data onto the stack
  for (buff_counter = 0;
    (buff_linesize = getline(&buffers[buff_counter], &buff_size, stdin)) != -1  && buff_counter < user_size; buff_counter++)
    {

      #ifdef DEBUG_TEST
      printf("pushing element \"%s\"\n", buffers[buff_counter]);
      #endif

      sub_stack[buff_counter] = create (buff_linesize); //create sub_stack

      if(sub_stack[buff_counter] == NULL)
      {
        printf("Not enough space to create sub_stack[%ld]\n", buff_counter);
        return 1;
      }

      for(int i = 0; i < buff_linesize; i++)
      {
        if(buffers[buff_counter][i] != '\0' && buffers[buff_counter][i] != '\n'){
          push(sub_stack[buff_counter], &buffers[buff_counter][i]);
        }
      }

      push(main_stack, sub_stack[buff_counter]); //push substack into stack

      #ifdef DEBUG_TEST
      printf("top of stack now \"%s\"\n", (char *) peek(main_stack));
      #endif
    }

    // Now pop the elements off the stack
    while (!isempty(main_stack))
    {

      Stack *sub = (Stack *) pop(main_stack);

      while(!isempty(sub))
      {
        char *element = (char *) pop(sub);
        printf("%c", *element);
      }
      printf("\n");
      destroy(sub); //free sub
    }


    //free memory
    destroy(main_stack);
    free(buffers);
  }
