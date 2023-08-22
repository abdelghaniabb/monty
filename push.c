#include "monty.h"
#include <string.h>

/**
 * push -
 * @stack:
 * @line_number:
 *
 * Return:
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value_str;
	int value;
	stack_t *new, *current;

	value_str = strtok(NULL, " \t\n");
	if (value_str == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (*value_str != '\0')
	{
		if (_isdigit(*value_str) == 0)
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value_str++;
	}
	value = _atoi(value_str);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = *stack;
	if (*stack == NULL)
	{
		(*stack)->prev = new;
		return;
	}
	*stack = new;
	/*if (stack == NULL)
	{
	printf("this is push1\n");
		stack = new;
		stack->next = NULL;
		stack->prev = NULL;
		printf("this is push1\n");
		return;
	}

	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	new->prev = current;
	current->next = new;
*/
	printf("this is push\n");
	return;
}
