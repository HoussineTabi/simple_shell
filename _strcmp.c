#include "shell.h"
/**
 * _strcmp - compares two string
 *
 * @str_nb1: first parameter
 * @str_nb2: the second parameter
 * Return: 0 if the tow string are equal and a number not nul atherwise
 */

int _strcmp(char *str_nb1, char *str_nb2)
{
	if (str_nb1 == NULL && str_nb2 == NULL)
		return (0);
	if (!str_nb1 || !str_nb2)
		return (-130);
	while (*str_nb1 != '\0' || *str_nb2 != '\0')
	{
		if (((*str_nb1) - (*str_nb2)))
			return (*str_nb1 - *str_nb2);
		str_nb1++;
		str_nb2++;
	}
	return (0);
}
