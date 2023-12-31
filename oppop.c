#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to stack
 * @line_number: number of line 
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(top);
}
