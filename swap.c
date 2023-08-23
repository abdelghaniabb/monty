#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;

	if ((*stack == NULL) || ((*stack)->next = NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
printf("fh\n");
	tmp = (*stack)->n;
	
	(*stack)->n = ((*stack)->next)->n;
	printf("fh1\n");
	((*stack)->next)->n = tmp;
	
}
