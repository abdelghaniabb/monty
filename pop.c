#include "monty.h"

/**
 * pop -  removes the top element of the stack.
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}
