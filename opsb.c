#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 * @stack: pointer to stack
 * @line_number: num in line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	second->n -= top->n;

	*stack = second;

	if (second->next)
		second->next->prev = second;

	free(top);
}
