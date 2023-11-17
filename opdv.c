#include "monty.h"

/**
 * div_op - divides the second top element of the stack
 * @stack: pointer to stack
 * @line_number: num of line
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n /= top->n;

	*stack = second;

	if (second->next)
		second->next->prev = second;

	free(top);
}
