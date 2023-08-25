#include "monty.h"
#include <string.h>

/**
 * push - pushes an element to the stack.
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value_str;
	int value;
	stack_t *new;
	/* extract the integer argument given to push */
	value_str = strtok(NULL, " \t\n");
	if (value_str == NULL || _isnumber(value_str) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	value = _atoi(value_str);
	/* allocate memory to the new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = NULL;
	/* add the new node to the stack*/
	if (*stack == NULL)
		*stack = new;
	else if ((*stack)->prev == NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		while ((*stack)->prev != NULL)
			*stack = (*stack)->prev;
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

