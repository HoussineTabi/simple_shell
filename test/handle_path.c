#include "shell.h"

/**
 * handle_path - checks if a path is exist
 *
 * @path: the path to check
 * @env: the envirnments variables
 * Return: NULL or the path
 */
char *handle_path(char *path, char **env)
{
	struct stat buffer;
	int count = 0, countpath = 0;
	char *full_path = NULL, *ptr = NULL, *token = NULL;
	char **ar = NULL;

	while (env[count])
	{
		ptr = _strdup(env[count]);
		token = strtok(ptr, "=");
		if (_strcmp(token, "PATH") != 0)
		{
			free(ptr);
			count++;
			continue;
		}
		token = _strdup(strtok(NULL, "="));
		ar = str_splite_to_words(token, ":");
		while (ar[countpath])
		{
			full_path = make_path(ar[countpath], path);
			if (!full_path)
				return (NULL);
			if (stat(full_path, &buffer) == 0)
			{
				free(ptr);
				free(token);
				_freearg(ar);
				return (full_path);
			}
			free(full_path);
			countpath++;
		}
		free(ptr);
		free(token);
		_freearg(ar);
		break;
	}
	return (NULL);
}

/**
 * str_splite_to_words - the funciton splite a string
 *
 * @str: the string to splite
 * @delim: the delimiter that uses to splite
 * Return: a table that contain the words string
 */
char **str_splite_to_words(char *str, const char *delim)
{
	char **words = NULL, *token = NULL;
	int count = nb_of_words(str, delim);

	if (!count)
		return (NULL);
	count = 0;
	words = malloc(sizeof(char *) * nb_of_words(str, delim) + 1);
	if (!words)
		return (NULL);
	token = strtok(str, delim);
	while (token)
	{
		words[count] = token;
		token = strtok(NULL, delim);
		count++;
	}
	words[count] = NULL;
	return (words);
}
/**
 * make_path - makes a path from absolut path and a file
 * @path: the absolut path
 * @file_name: the name of the file
 * Return: a new new path
 */
char *make_path(char *path, char *file_name)
{
	char *full_path = NULL;
	int count = 0, i;

	if (file_name == NULL || path == NULL)
		return (NULL);
	full_path = malloc(sizeof(char) * (_strlen(path) + _strlen(file_name) + 2));
	while (path[count] != '\0')
	{
		full_path[count] = path[count];
		count++;
	}
	full_path[count] = '/';
	i = count + 1;
	count = 0;
	while (file_name[count] != '\0')
	{
		full_path[i] = file_name[count];
		count++;
		i++;
	}
	return (full_path);
}

