#include <stdlib.h>
#include "printf.h"
#include "help.h"
#include "str_func.h"
#include "error.h"

/**
* help - command help guide for built-in
* @command: commande split
* @line: line of commande
* @counter: counter of loop simple shell
* @name: name of program
* Return: 0 Success, 2 if error
*/
int help(char **command, char *line, int counter, char *name)
{
	int i = 0;
	help_t tab_help[] = {
		{"help", help_help},
		{"exit", help_exit},
		{"\0", NULL},
	};

	(void)line;

	while (tab_help[i].name[0] != '\0')
	{
		if (_strcmp(tab_help[i].name, command[1]) == 0)
		{
			tab_help[i].help();
			return (0);
		}
		i++;
	}
	return (error_help(name, command, counter));
}

/**
* help_help - help command for command help
*/
void help_help(void)
{
	_printf("help: [pattern ...]\n");
	_printf("\tDisplay information about builtin commands.\n\n");
	_printf("\tDisplays brief summaries of builtin commands.  If PATTERN is\n");
	_printf("\tspecified, gives detailed help on all");
	_printf(" commands matching PATTERN,\n");
	_printf("\totherwise the list of help topics is printed.\n");
}
