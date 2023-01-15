#include "shell.h"
#include "help.h"

/**
* check_built_in - check of the command is a built-in
* @command: command
* @line: line of command
* @counter: counter of while
* @name: name of program
*
* Return: 1 if the command is a built-in else -1 not a built-in
*/
int check_built_in(command_t *command, char *line, int counter, char *name)
{
	int i = 0;
	built_in_t command_built_in[] = {
		{"env", print_env},
		{"exit", exit_sh},
		{"help", help},
		{"cd", change_directory},
		{"\0", NULL},
	};

	while (command_built_in[i].command[0])
	{
		if (_strcmp(command_built_in[i].command, command->command_name) == 0 &&
		_strlen(command_built_in[i].command) == _strlen(command->command_name))
		{
			return (command_built_in[i].built_in(command, line, counter, name));
		}
		i++;
	}
	return (-1);
}

