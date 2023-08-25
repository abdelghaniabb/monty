#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	current = *stack;
	while (current->prev != NULL)
		current = current->prev;

	if (current == NULL)
	{
		/*fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);*/
		free_stack(stack);
		exit(EXIT_FAILURE);
	}


	if (current->n < 32 || current->n > 176)
	{
		/*fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);*/
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	while (current != NULL)
	{
		if (current->n < 32 || current->n > 176)
		{
			/*fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);*/
			_putchar('\n');
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		_putchar(current->n);
		current = current->next;
	}

}

