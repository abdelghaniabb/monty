#include "monty.h"

/**
 * rotr -  rotates the stack to the bottom.
 * The last element of the stack becomes the top element of the stack
 * @stack: the head of the doubly linked list represented the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    if (*stack == NULL)
        return;

    /* go to the the head of the stack if the *stack does not point to the head*/
    while ((*stack)->prev != NULL)
    {
        *stack = (*stack)->prev;
    }

    current = *stack;
    current = current->next;
    while (current != NULL)
    {
        current->n = current->prev->n;
        current = current->next;
    }

    (*stack)->n = current->prev->n;
}
