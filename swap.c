#include "monty.h"

/**
 * swap -  swaps the top two elements of the stack.
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

