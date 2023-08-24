#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * The result is stored in the second top element of the stack,
 * and the top element is removed
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);

}
