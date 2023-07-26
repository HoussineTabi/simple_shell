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
		free(line);
		line = NULL;
		if (!(stat(ar[0], &buffer) == 0))
		{
<<<<<<< HEAD
=======
			variable = ar[0];
			ar[0] = handle_path(variable, env);
>>>>>>> 693c81c9ebeb4d67fe9f4a26960f5701fc23ac45
			if (!ar[0])
			{
				_perror(argv[0], variable);
				_freearg(ar);
<<<<<<< HEAD
				perror("./shell");
=======

>>>>>>> 693c81c9ebeb4d67fe9f4a26960f5701fc23ac45
				continue;
			}
		}
		fork_child_parent(line, ar, env);
	}
	free(line);
	exit(0);
}

/**
 * _perror - prints an the error if there is an error
 *
 * @str1: the string number 1
 * @str2: the string number 2
 */
void _perror(char *str1, char *str2)
{
	write(2, str1, _strlen(str1));
	write(2, ": 1: ", _strlen(": 1: "));
	write(2, str2, _strlen(str2));
	write(2, ": not found\n", _strlen(":not found\n"));
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
	{
		_freearg(ar);
		exit(0);
	}
	else if (pid == 0)
	{
		i = _execmd(ar, env);
		if (i == -1)
		{
			perror("./shell");
			exit(0);
		}
	}
	else
		wait(NULL);
	_freearg(ar);
	ar = NULL;
}
