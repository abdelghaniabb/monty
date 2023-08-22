#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/* Create an array of instructions*/
instruction_t instructions[] = {
	{"push", push},
	{"pall", pall}
};

/**
 * main - check code
 * @argc: number of arguments passed to the program
 * @argv: pointer array which points to each argument passed to the program
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *opcode, line[50];
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	/* read the file and ecxicute the opcode*/
	while (fgets(line, 50 * sizeof(char), file) != NULL)
	{
		opcode = strtok(line, " \t\n");
		execute_opcode(opcode, &stack, line_number);
		line_number++;
	}
	return (0);
}
