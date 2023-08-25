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
 * _isnumber - checks if the string is a number
 * @str: the string to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isnumber(char *str)
{
	int i;
	int len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		if ((*str < '0' || *str > '9') && *str != '-')
			return (0);
		str++;
	}

	return (1);
}

/**
 * _strlen -  returns the length of a string
 * @s: string
 *
 * Return: length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
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

