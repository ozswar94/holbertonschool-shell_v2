#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>

#include "shell.h"
#include "error.h"

/**
* change_directory - change the directory
* @command: command
* @line: llne of command
* @counter: counter of simple shell
* @name: name of program
* Return: 2 if error otherwise 0
*/
int change_directory(command_t *command, char *line, int counter, char *name)
{
	char path[PATH_MAX];

	(void)line;
	getcwd(path, PATH_MAX);

	if (!command->command_argument[1])
	{
		_setenv("OLDPWD", path);
		chdir(_getenv("HOME"));
	}
	else if (_strstr("-", command->command_argument[1]))
	{
		chdir(_getenv("OLDPWD"));
		_setenv("OLDPWD", path);
	}
	else
	{
		if (chdir(command->command_argument[1]) < 0)
		{
			error_message_cd(name, counter);
			return (2);
		}
		_setenv("OLDPWD", path);
	}
	getcwd(path, PATH_MAX);
	_setenv("PWD", path);
	return (0);
}


/**
* error_message_cd - change the directory
* @counter: counter of simple shell
* @name: name of program
* Return: Error message
*/
void error_message_cd(char *name, int counter)
{
	char err_msg[50];

	_strcpy(err_msg, name);
	_strcat(err_msg, ": ");
	_strcat(err_msg, _getnbr(counter));
	_strcat(err_msg, ": ");
	_strcat(err_msg, "cd");

	perror(err_msg);
}
