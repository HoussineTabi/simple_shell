#include "shell.h"

/**
 * nb_of_words - calculate the number of words in a string given
 * @str: the string
 * @delim: the delimiter uses to splite the string
 * Return: the number of words in the string
 */

int nb_of_words(char *str, const char *delim)
{
	int nb_of_word = 0;
	char *strdu = NULL, *token = NULL;

	if (!str)
		return (0);
	strdu = _strdup(str);
	token = strtok(strdu, delim);
	while (token)
	{
		nb_of_word++;
		token = strtok(NULL, delim);
	}
	free(strdu);
	return (nb_of_word);
}
