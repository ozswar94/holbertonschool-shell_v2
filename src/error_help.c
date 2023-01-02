#include "printf.h"
#include <unistd.h>
#include "str_func.h"

/**
 * error_help - prints errors to standard error
 * @name: name of file
 * @command: command with the error
 * @counter: number of time the loop was made
 * Return: Error code
 */


int error_help(char *name, char **command, int counter)
{
	char *c;

	if (isatty(STDERR_FILENO))
	{
		c = _getnbr(counter);
		write(STDERR_FILENO, name, _strlen(name));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, c, _strlen(c));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command[1], _strlen(command[1]));
		write(STDERR_FILENO, ": not help topic match", 23);
		write(STDERR_FILENO, "\n", 1);
		free(c);
	}
	return (2);
}

