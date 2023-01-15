#include "shell.h"

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
