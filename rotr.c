#include "monty.h"

/**
 * rotr -  rotates the stack to the bottom.
 * The last element of the stack becomes the top element of the stack
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;
	int tmp1, tmp2;

	if (*stack == NULL)
		return;

	/* go to the the head of the stack if the *stack does not point to the head*/
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	current = *stack;
	tmp1 = current->n;
	current = current->next;
	while (current->next != NULL)
	{
		tmp2 = tmp1;
		tmp1 = current->n;
		current->n = tmp2;
		current = current->next;
	}

	(*stack)->n = current->n;
	current->n = tmp1;

}

