#include "monty.h"

/**
 * execute_opcode - Find the corresponding function
 * for the opcode and execute it
 * @opcode: operator code
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	/* create an array of instructions*/
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add}
	};
	int instructions_lenght = 6;

	/* check if the opcode is within the array of instructions*/
	for (i = 0; i < instructions_lenght; i++)
	{
		if (_strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

