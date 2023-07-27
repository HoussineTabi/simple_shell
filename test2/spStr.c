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
	words = malloc(sizeof(char *) * (nb_of_words(str, delim) + 1));
	if (!words)
		return (NULL);
	token = strtok(str, delim);
	while (token)
	{
		words[count] = _strdup(token);
		token = strtok(NULL, delim);
		count++;
	}
	words[count] = NULL;
	return (words);
}
