#include "shell.h"

/**
 * _freearg - function that free a table of argument
 * @ar: table of argument
 */

void _freearg(char **ar)
{
	int count = 0;

	if (ar != NULL)
	{
		while (ar[count])
		{
			free(ar[count]);
			count++;
		}
		free(ar);
	}
}
