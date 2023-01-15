#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include "str_func.h"
#include "printf.h"
#include "command.h"


/**
 * struct built_in_s- struct for check built-in function
 * @command: name of command
 * @built_in: function launch
 */
typedef struct built_in_s
{
	char command[100];
	int (*built_in)(command_t *command, char *, int, char *);
} built_in_t;

extern char **environ;

void prompt(void);
int exit_sh(command_t *command, char *line, int counter, char *name);
int change_directory(command_t *command, char *line, int counter, char *name);
int hsh(char *name);
int print_env(command_t *command, char *line, int counter, char *name);
char *_getenv(char *name);
int check_built_in(command_t *command, char *line, int counter, char *name);
char *search_path(char *command);
int run_command(command_t *command, char **env);
void _setenv(char *name, char *value);
void handler_ctrlc(int c);
void clean_line(char *line);

/*help*/
void help_exit(void);

#endif /*SHELL_*/
