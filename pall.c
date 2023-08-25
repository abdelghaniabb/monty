#include "monty.h"

/**
 * pall -  prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	if (*stack == NULL)
		return;

	/* scroll in the linked list and print all the values starting from the top*/
	current = *stack;
	while (current->prev != NULL)
		current = current->prev;
	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

