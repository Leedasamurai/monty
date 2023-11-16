#include "monty.h"

/**
 * pint - value at the top of the stack
 * @stack: pointer to stack
 * @line_number: number in lines of Monty byte code file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
