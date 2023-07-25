#include "shell.h"

/**
 * _getline - is a funciton that get a line from the standard input
 *
 * @line: the adrees of the line
 * @n: the size of the line
 * @stream: a pointer to the file to read into
 * @stream: is a pointer to the file that we want to read into
 * Return: the number of character read or -1 in faild
 */

size_t _getline(char **line, size_t *n, FILE *stream)
{
	int nwrite;
	size_t count = 0;
	char buffer[1024];

	if (line == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*line != NULL)
		free(*line);
	while (count < 1024)
	{
		nwrite = fread(buffer + count, sizeof(char), 1, stream);
		if (nwrite == -1)
			return (-1);
		if (buffer[count] == '\n')
			break;
		count++;
	}
	*line = malloc(sizeof(char) * (count));
	if (line == NULL)
		return (-1);
	*n = count;
	count = 0;
	while (count <= *n)
	{
		(*line)[count] = buffer[count];
		count++;
	}
	(*line)[count] = '\0';
	return (*n);
}
