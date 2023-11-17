#include "monty.h"

/**
 * swap - swaps the top two elements
 * @stack: pointer to stack
 * @line_number: line num
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	top->next = second->next;
	if (second->next)
		second->next->prev = top;

	second->prev = NULL;
	second->next = top;
	top->prev = second;

	*stack = second;
}
