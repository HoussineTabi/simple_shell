#include "shell.h"

/**
 * _isexit - cuts the execution of the process
 *
 * @ar: the command
 * @line: the second parameter
 */
void _isexit(char **ar, char *line)
{
	int exit_value = 0;

	if (!_strcmp(ar[0], "exit"))
	{
		free(line);
		if (_isdigit(ar[1]))
		{
			exit_value = _atoi(ar[1]);
			_freearg(ar);
			if (exit_value < 0)
				exit_value = 0;
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
	while (*str == ' ')
		str++;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str > 57 || *str < 48)
			return (0);
		str++;
	}
	return (1);
}
