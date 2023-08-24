#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (((*stack)->n < 65 || (*stack)->n > 90) && ((*stack)->n < 97 || (*stack)->n > 122))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	_putchar((*stack)->n);
}

