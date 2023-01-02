#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include "str_func.h"
#include "printf.h"

/**
 * struct built_in_s- struct for check built-in function
 * @command: name of command
 * @built_in: function launch
 */
typedef struct built_in_s
{
	char command[100];
	int (*built_in)(char **, char *, int, char *);
} built_in_t;

extern char **environ;

void prompt(void);
int exit_sh(char **command, char *line, int counter, char *name);
int change_directory(char **command, char *line, int counter, char *name);
int simple_shell(char *name);
int print_env(char **command, char *line, int counter, char *name);
char *_getenv(char *name);
int check_built_in(char **command, char *line, int counter, char *name);
char *search_path(char *command);
void free_dptr(char **ptr);
void run_command(char *command_path, char **command, char **env);
void _setenv(char *name, char *value);

/*help*/
void help_exit(void);

#endif /*SHELL_*/
