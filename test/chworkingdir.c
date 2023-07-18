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
		newpath = strdup(strcat(getcwd(NULL, 1024), strdup(path)));
		printf("%s\n", newpath);
		if (chdir(path) != -1)
			printf("the working directory is changed successfuly \n");
		else
			printf("the path isn't correct\n");
		free(newpath);
	}
}
