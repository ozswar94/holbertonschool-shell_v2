#ifndef HELP_H
#define HELP_H

#include "command.h"

/**
 * struct help_s - struct for help built-in
 * @name: name of command
 * @help: function launch
 */
typedef struct help_s
{
	char name[20];
	void (*help)(void);
} help_t;

int help(command_t *command, char *line, int counter, char *name);
void help_help(void);
void help_exit(void);

#endif /*HELP_H*/
