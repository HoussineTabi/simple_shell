#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/stat.h>
int _strcmp(char *, char *);
char *_strdup(char *);
int _strlen(char *);
extern char **environ;
char *_get_command(void);
int _execmd(char **, char **);
void prompt(void);
void _freearg(char **);
void _isexit(char **);
size_t _getline(char **, size_t *, FILE *);
int _find_char(char *str, char c, size_t size);
char *_strtok(char *str, char *sepa);
char *_is_a_variable(char *);
void _change_dir(char *);
char *handle_path(char *path, char **env);
char **str_splite_to_words(char *str, const char *delim);
void fork_child_parent(char *line, char **ar, char **env);
int nb_of_words(char *str, const char *delim);
char *make_path(char *, char *);
int _isdigit(char *str);
int _atoi(char *);
int _unset(char *, char ***);

#endif /* SHELL_H */
