#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);

}

