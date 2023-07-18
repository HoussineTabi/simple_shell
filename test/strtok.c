#include "shell.h"

/**
 * _strtok - tokenizes string given to words
 * @str: the string to token
 * @sepa: the separatur of words
 * Return: the chain of words
 */

char *_strtok(char *str, char *sepa)
{
	char *beginstr = NULL;
	char *token = NULL;
	size_t len;

	if (str)
		beginstr = str;
	if (beginstr == NULL || *beginstr == '\0')
		return (NULL);
	if (sepa == NULL || strlen(sepa) == 0)
		return (str);
	if (str)
	{
	len = strlen(str);
	while (*sepa != '\0')
	{
		_find_char(str, *sepa, len);
		sepa++;
	}
	return (str);
	}
	while (*beginstr != '\0')
		beginstr++;
	beginstr += 1;
	if (*(beginstr) == '\0')
	{
		beginstr = NULL;
		return (NULL);
	}
	token = beginstr;
	return (token);
}


/**
 * _find_char - find out if the string contains a character
 * @str: the string
 * @c: the caracter
 * @size: the size of the string
 * Return: 0 if the string contains the character and 1 otherwise
 */
int _find_char(char *str, char c, size_t size)
{
	size_t count = 0;
	int i = 0;

	if (size == 0 || str == NULL || c == '\0')
		return (1);
	while (count < size)
	{
		if (str[count] == c)
		{
			str[count] = '\0';
			i = 1;
		}
		count++;
	}
	if (i == 1)
		return (0);
	return (1);
}
