#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	printf("%i\n", (*stack)->n);
}

