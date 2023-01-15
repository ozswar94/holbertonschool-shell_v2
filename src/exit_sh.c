#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
#include "error.h"


/**
* exit_sh - exit simple shell
* @command: command
* @line: llne of command
* @counter: counter of simple shell
* @name: name of program
* Return: 2 if error exit
*/
int exit_sh(command_t *command, char *line, int counter, char *name)
{
	int status;

	if (_strlen_2d(command->command_argument))
		status = _atoi(command->command_argument[1]);
	else
		status = 0;

	if (status >= 0)
	{
		free(line);
		delete_command(&command);
		exit(status);
	}
	else
	{
		error_exit(name, command->command_argument, counter);
	}
	return (2);
}


/**
* help_exit - print in terminal info for use exit
*/
void help_exit(void)
{
	_printf("exit: exit [n]\n");
	_printf("\tExit the shell.\n\n");
	_printf("\tExits the shell with a status of N.");
	_printf("  If N is omitted, the exit status\n");
	_printf("\tis that of the last command executed.\n");
}
