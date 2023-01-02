#include <errno.h>
#include <stdio.h>
#include "printf.h"
#include <string.h>
#include <unistd.h>
#include "str_func.h"

/**
 * error_not_found - prints errors to standard error
 * @name: name of file
 * @command: command with the error
 * @counter: number of time the loop was made
 * Return: Error code
 */

int error_not_found(char *name, char **command, int counter)
{
	char *c;

	if (isatty(STDERR_FILENO))
	{
		c = _getnbr(counter);
		write(STDERR_FILENO, name, _strlen(name));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, c, _strlen(c));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command[0], _strlen(command[0]));
		write(STDERR_FILENO, ": not found", 12);
		write(STDERR_FILENO, "\n", 1);
		free(c);
	}
	return (2);
}

