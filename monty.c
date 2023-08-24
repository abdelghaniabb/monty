#include "monty.h"
#include <string.h>

void noyhinb(void);
FILE *file;
/**
 * main - check code
 * @argc: number of arguments passed to the program
 * @argv: pointer array which points to each argument passed to the program
 *
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{

	char *opcode, line[50];
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	/* check the number of arguments given by the user */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack(&stack);
		exit(EXIT_FAILURE);
	}

	/* open the file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_stack(&stack);
		exit(EXIT_FAILURE);
	}

	/* read the file and ecxicute the opcode*/
	while (fgets(line, 50 * sizeof(char), file) != NULL)
	{
		opcode = strtok(line, " \t\n");
		if (opcode != NULL)
			execute_opcode(opcode, &stack, line_number);
		line_number++;
	}

	free_stack(&stack);
	return (0);
}

