#include "shell.h"

/**
 * _unset - unsets an environment variable
 *
 * @name: the vaame of the environment variable
 * @env: the table of the environment variable
 * Return: 0 in success and 1 otherwise
 */

int _unset(char *name, char ***env)
{
	char *name_value = NULL, *token = NULL;
	int count = 0;

	if (!name || !(*env))
		return (1);
	while ((*env)[count])
	{
		name_value = _strdup((*env)[count]);
		token = strtok(name_value, "=");
		if (!_strcmp(name, token))
		{
			free(name_value);
			break;
		}
		count++;
		free(name_value);
	}
	if (!(*env)[count])
		return (1);
	while ((*env)[count])
	{
		(*env)[count] = (*env)[count + 1];
		count++;
	}
	return (0);
}
