#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include "shell.h"
#include "error.h"
#include "shell_lexer.h"

/**
* hsh - main function for run hsh
* @name: name of programme
*
* Return: 2 if EOF, 0 Normaly
*/
int hsh(char *name)
{
	char *line = NULL;
	size_t len_line = 0;
	token_shell_t *token = NULL;
	int counter = 1, error_command = 0;
	command_t *command = NULL, *command_tmp;

	do {
		prompt(); /*show the promt*/
		signal(SIGINT, handler_ctrlc); /*handle sinal ctrl + c*/
		if (getline(&line, &len_line, stdin) == EOF)
		{
			free(line);
			delete_command(&command);
			return (-1);
		}
		token = tokenize(line);
		command = interpret_token(&token);
		command_tmp = command;
		while (command_tmp)
		{
			error_command = check_built_in(command_tmp, line, counter, name);
			if (error_command < 0)
			{
				command->command_path = search_path(command->command_name);
				if (command->command_path != NULL)
					error_command  = run_command(command_tmp, environ);
				else
					error_not_found(name, command->command_argument, counter);
			}
			command_tmp = command_tmp->next;
		}
		delete_command(&command);
	} while (counter++);
	return (0);
}


/**
* run_command - run command in new processus
* @command: the line with argument
* @env: environ variable
* Return: status
*/
int run_command(command_t *command, char **env)
{
	pid_t child;
	int status;

	if (command->command_path == NULL || command->command_argument == NULL)
		return (-1);

	child = fork();
	if (child == 0)
	{
		dup2(command->fd, STDOUT_FILENO);
		if ((execve(command->command_path, command->command_argument, env)) == -1)
		{
			perror("Error:");
			exit(status);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (command->fd > 2)
			close(command->fd);
		wait(&status);
	}
	return (status);
}
