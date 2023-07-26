#include "shell.h"

/**
 * _change_dir - is going to change the working directory
 * @path: the command that containing the path
 */
void _change_dir(char *path)
{
	char *newpath;

	if (path != NULL)
	{
		newpath = NULL;
		write(1, "working direc", sizeof("workding direc"));
		if (chdir(path) != -1)
			write(1, "the dir is changed\n", sizeof("the dir is changed\n"));
		else
			write(1, "the path isn't correct\n", sizeof("the path isn't correct\n"));
		free(newpath);
	}
}
