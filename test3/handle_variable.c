#include "shell.h"

/**
 * _is_a_variable - finds out if there is a variable in the command line
 * @str: the string to check
 * Return: it's value if it's variable NULL otherwise
 */
char *_is_a_variable(char *str)
{
	char **env = environ, *token = NULL;
	int count = 0;

	if (str == NULL)
		return (NULL);
	str = strtok(str, "$");
	while (env[count])
	{
		token = strtok(env[count], "=");
		if (_strcmp(str, token) == 0)
		{
			str = _strdup(strtok(NULL, "="));
			return (str);
		}
		count++;
	}
	return (NULL);
}
