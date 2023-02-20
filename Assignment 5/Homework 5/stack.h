/** stack.h
 * Header file for stack data structure implementation
 *
 * @author Blake Nelson, Sean Arackal
 *
 */
#ifndef STACK_H
#define STACK_H

typedef struct stack {
  int num_elements;        /**< Num elements in the stack - 0 when empty */
  int max_elements;        /**< Size of elemnts array */
  void **top;              /**< Ptr to empty slot at current top of stack */
  void **base;             /**< Ptr to bottom (base) of the stack */
  void *elements[];        /**< Elements of the stack */
} Stack;

/** Function prototypes for stack operations
 */

void * peek (Stack *stack);
void * pop (Stack *stack);
void * push (Stack *stack, void *element);
int isempty (Stack *stack);
int numelements (Stack *stack);
int maxelements (Stack *stack);
Stack * create (int max_elements);
void destroy (Stack *stack);

#endif
