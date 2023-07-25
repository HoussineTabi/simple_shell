#include "shell.h"

/**
 * _setenv - is a function that sets an environ variable
 *
 * @name: the name of the environment variable
 * @value: the value of the new envurin vari
 * @overwrite: the value of overwrite
 * @env: the table of the environment variable
 *
 * Return: 0 in success and 1 otherwise
 */

int _setenv(char *name, char *value, int overwrite, char ***env)
{
	int count = 0;
	char *name_value = NULL, *token = NULL;
	char **new_env = NULL;

	if (!name || !value)
		return (-1);
	while ((*env)[count])
	{
		name_value = _strdup((*env)[count]);
		token = strtok(name_value, "=");
		if (!_strcmp(name, token))
		{
			if (overwrite)
				(*env)[count] = make_env(name, value);
			free(name_value);
			return (0);
		}
		count++;
		free(name_value);
	}
	printf("count %d\n", count);
	new_env = malloc(sizeof(char *) * (count + 2));
	count = 0;
	while ((*env)[count])
	{
		new_env[count] = _strdup((*env)[count]);
		printf("%s \n", new_env[count]);
		count++;
	}
	new_env[count] = make_env(name, value);
	new_env[count + 1] = NULL;
	*env = new_env;
	return (0);
}

/**
 * make_env - make name=value of an environment variable
 *
 * @name: string the name of the environment variable
 * @value: the value of the environ variable
 * Return: case of success name=value is returned othewise NULL is returned
 */
char *make_env(char *name, char *value)
{
	int count = 0;
	char *name_value = NULL;

	if (!name || !value)
		return (NULL);
	name_value = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	if (!name_value)
		return (NULL);
	while (*name)
	{
		name_value[count] = *name;
		name++;
		count++;
	}
	name_value[count] = '=';
	count++;
	while (*value)
	{
		name_value[count] = *value;
		value++;
		count++;
	}
	return (name_value);
}
