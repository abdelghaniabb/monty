#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL)
		return;
	printf("this is pop\n");
	current = *stack;
	/*while (current->next != NULL)
		current = current->next;*/
	printf("this is pop\n");
	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->prev;
	}

	printf("this is pop\n");
}
