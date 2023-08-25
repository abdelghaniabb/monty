#include "monty.h"

/**
 * free_stack - free all the allocate memory and close the opened file
 * @stack: the head of the doubly linked list represented the stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	fclose(file);

	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}

}

