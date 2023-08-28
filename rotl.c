#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * The top element of the stack becomes the last one, and 
 * the second top element of the stack becomes the first one
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;
	int value;

	if (*stack == NULL)
		return;

	/* go to the the head of the stack if the *stack does not point to the head*/
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	current = *stack;
	value = current->n;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}

	current->n = value;
}
