#include "monty.h"

/**
 * pall - the values on the stack
 * @stack: pointer to stack
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
