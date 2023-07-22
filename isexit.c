#include "shell.h"

/**
 * _isexit - cuts the execution of the process
 *
 * @ar: the command
 */
void _isexit(char **ar)
{
	int exit_value;

	if (!_strcmp(ar[0], "exit"))
	{
		if (_isdigit(ar[1]))
		{
			exit_value = atoi(ar[1]);
			_freearg(ar);
			exit(exit_value);
		}
		_freearg(ar);
		exit(0);
	}
}
/**
 * _isdigit - determines is a string is contain just integer
 * @str: the string
 * Return: 1 if the string contains just integers and 0 els
 */
int _isdigit(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str > 57 || *str < 48)
			return (0);
		str++;
	}
	return (1);
}
