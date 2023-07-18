#include "shell.h"
/**
 * main - this function displys a prompt
 * @ac: the counter arguments
 * @argv: the vector argument
 * @env: the envirnment arguments
 * Return: 0 if success or 1 otherwise
 */

int main(int ac, char **argv, char **env)
{
	char *line = NULL, **ar = NULL;
	size_t n;
	bool from_pipe = false;
	struct stat buffer;

	(void) argv;
	while (ac)
	{
		if (isatty(STDIN_FILENO) != 0)
			from_pipe = true;
		if (from_pipe)
			prompt();
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(1);
		}
		ar = str_splite_to_words(line, " \n");
		if (!ar)
			continue;
		_isexit(ar);
		if (!(stat(ar[0], &buffer) == 0))
		{
			ar[0] = handle_path(ar[0], env);
			if (!ar[0])
			{
				_freearg(ar);
				perror("./hsh");
				continue;
			}
		}
		fork_child_parent(line, ar, env);
	}
	free(line);
	exit(0);
}
/**
 * fork_child_parent - this function double the process
 * @line: string the line command
 * @ar: the line that splited to argument
 * @env: the envirnemnt variable
 */

void fork_child_parent(char *line, char **ar, char **env)
{
	pid_t pid;
	int i;

	(void)line;
	pid = fork();
	if (pid == -1)
		exit(0);
	else if (pid == 0)
	{
		i = _execmd(ar, env);
		if (i == -1)
		{
			perror("./hsh");
			exit(0);
		}
	}
	else
		wait(NULL);
	_freearg(ar);
}
