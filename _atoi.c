#include "shell.h"
/**
 * _atoi - converts a string of integrs to an integer
 *
 * @str: the parameter string
 * Return: the value of string in success and 0 otherwise
 */

int _atoi(const char *str)
{
	int str_enteger_value = 0, ten = 1;
	int count = 0;
	int checker = 0;

	if (!str || *str == '\0')
		return (0);
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		checker = 1;
		str++;
	}
	while (str[count])
	{
		if (str[count] > 47 && str[count] < 58)
			count++;
		else
			break;
	}
	if (!count)
		return (0);
	count--;
	while (count >= 0)
	{
		str_enteger_value += ((str[count] - 48) * ten);
		ten = ten * 10;
		count--;
	}
	if (!checker)
		return (str_enteger_value);
	return (-str_enteger_value);
}
