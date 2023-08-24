#include "monty.h"

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);

}

