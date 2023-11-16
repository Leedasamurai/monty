#define _POSIX_C_SOURCE 200809L

#include "monty.h"

/**
 * push - pushes element into stack
 * @stack: pointer to stack
 * @value: value of Monty byte code file
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

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

/**
 * main - Monty interpreter entry point
 * @argc: command-line arg amount
 * @argv: Arr of the command-line arg strings
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;
	char *line;
	size_t len;
	unsigned int line_number;
	char *opcode;
	char *arg;
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;

	line = NULL;
	len = 0;
	line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (!arg)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}

				value = atoi(arg);
				push(&stack, value);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}

	free(line);
	fclose(file);

	while (stack)
	{
		stack_t *temp = stack->next;
		free(stack);
		stack = temp;
	}

	return EXIT_SUCCESS;
}
