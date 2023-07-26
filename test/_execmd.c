#include "shell.h"

/**
 * _execmd - this funciton executes a command
 *
 * @env: the envirnments variable arguments
 * @ar: the arguments vector
 * Return: 0 if the command is exist and 1 otherwise
 */

int _execmd(char **ar, char **env)
{
	int i = 0;
	i = execve(ar[0], ar, env);
	return (i);

}
