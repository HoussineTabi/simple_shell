#include "shell.h"

/**
 * _strlen - returns the length of a string
 *
 * @str: the string
 * Return: the length of the string
 */
int _strlen(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '\0')
		return (0);
	return (1 + _strlen(++str));
}
