#define _POSIX_C_SOURCE 200809L

#include "monty.h"

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
	stack_t *temp;

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
			else if (strcmp(opcode, "pint") == 0)
			{
				pint(&stack, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(&stack, line_number);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				swap(&stack, line_number);
			}
			else if (strcmp(opcode, "add") == 0)
			{
				add(&stack, line_number);
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
		temp = stack->next;
		free(stack);
		stack = temp;
	}

	return (EXIT_SUCCESS);
}
