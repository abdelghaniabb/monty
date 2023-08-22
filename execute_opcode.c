#include "monty.h"

/**
 * execute_opcode - Find the corresponding function for the opcode and execute it
 * @opcode: operator code
 *
 * Return: void
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	long unsigned int i;

	for (i = 0; i < 3; i++)
	{
		if (_strcmp(opcode, instructions[i].opcode) == 0)
		{
			printf("%s\n", opcode);
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
