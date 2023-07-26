#include "shell.h"

/**
 * _strdup - duplicate a string
 * @str: the string to duplicate
 *
 * Return: the duplicated or NULL in filure
 */

char *_strdup(char *str)
{
	char *copy = NULL;
	int i = 0;

	if (!str)
		return (NULL);
	copy = malloc(sizeof(char) * (_strlen(str) + 1));
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
