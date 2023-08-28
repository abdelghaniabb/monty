#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	/* This is the default behavior of the program. so we have nothing to change*/
	nop(stack, line_number);
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void queue(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new, *current_old, *current_new;

	if (*stack == NULL)
		return;

	/* go to the the head of the stack if the *stack does not point to the head*/
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	/* create cursers to  move throught the old stack and the new stack*/
	current_old = *stack;
	new = *stack;
	new->next = NULL;
	new->prev = current_old->next;
	current_new = new;
	while (current_old != NULL)
	{
		current_new->prev = current_old->next;
		current_new->next = current_old->prev;

		current_new = current_new->prev;
		current_old = current_old->next;
	}

	/* return the new stack to the head of the old stack and free the new stack*/
	*stack = new;
	(*stack)->next = new->next;
	(*stack)->prev = new->prev;

}

