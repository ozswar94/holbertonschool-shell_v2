#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include "shell.h"
#include "error.h"

/**
* handler_ctrlc - manage ctrl + c
* @c: void
*/
void handler_ctrlc(int c)
{
	(void)c;
	_putchar('\n');
	prompt();
}


/**
* clean_line - remove char newline in line and replace \t to space
* @line: line of command
*
*/
void clean_line(char *line)
{
	unsigned int i;
	unsigned int size;

	size = _strlen(line) - 1;
	if (line[size] == '\n')
		line[size] = '\0';

	for (i = 0; line[i] != '\0'; i++)
		if (line[i] == '\t')
			line[i] = ' ';
}


/**
* simple_shell - main function for run simple_shell
* @name: name of programme
*
* Return: 2 if EOF, 0 Normaly
*/
int simple_shell(char *name)
{
	char *line = NULL;
	char *command_path = NULL;
	char **command = NULL;
	size_t len_line = 0;
	int counter = 1;
	int error_command = 0;

	do {
		prompt();/*show the promt*/
		signal(SIGINT, handler_ctrlc); /*handle sinal ctrl + c*/
		if (getline(&line, &len_line, stdin) == EOF)
		{
			free(line);
			return (error_command);
		}
		clean_line(line); /*remove new line and tab*/
		command = _strsplit(line, ' '); /*split word by word*/
		if (command == NULL)
			continue;
		error_command = check_built_in(command, line, counter, name);
		if (error_command < 0)
		{
			command_path = search_path(command[0]); /*search in $PATH*/
			if (command_path != NULL)
			{
				run_command(command_path, command, environ);
				error_command = 0;
			}
			else
			{
				error_not_found(name, command, counter);
				error_command = 2;
			}
		}
		free_dptr(command);
	} while (counter++);

	return (0);
}


/**
* run_command - run command in new processus
* @command_path: absolute path of file
* @command: the line with argument
* @env: environ variable
*
*/
void run_command(char *command_path, char **command, char **env)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command_path, command, env) == (-1))
		{
			perror("Error:");
			exit(2);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		free(command_path);
	}
}
