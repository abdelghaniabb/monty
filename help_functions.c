#include "monty.h"
#include <unistd.h>

/**
 * _atoi - convert a string to an integer
 * @s: string
 *
 * Return: 0 if there are no numbers in the string
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;

	while (*s != '\0')
	{
		if (*s == '-')
			sign = -1;

		else if (*s >= '0' && *s <= '9')
			result = result * 10 + (*s - '0');

		else if (result > 0)
			break;

		s++;
	}

	return (sign * result);
}


/**
 * _strcmp - copies a string
 * @s1: the destination string
 * @s2: the source string
 *
 * Return: pointer to the destination string
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);

	else
		return (0);
}

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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

