#include <stdlib.h>
#include "shell.h"


/**
* print_env - print environ varaible
* @command: command
* @line: llne of command
* @counter: counter of simple shell
* @name: name of program
* Return: 0 if success
*/
int print_env(char **command, char *line, int counter, char *name)
{
	int i = 0;

	(void)line;
	(void)command;
	(void)counter;
	(void)name;
	while (environ[i] != NULL)
	{
		_printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}


/**
* _getenv - content of name env
* @name: variable env
* Return: content of variable env or NULL
*/
char *_getenv(char *name)
{
	int i = 0;
	unsigned int j;
	unsigned int k;

	while (environ[i] != NULL)
	{
		if (_strstr(environ[i], name))
		{
			j = 0;
			k = 0;
			while (name[j])
			{
				if (environ[i][j] == name[j])
					k++;
				j++;
			}
			if (k == _strlen(name))
			return (_strstr(environ[i], name) + _strlen(name) + 1);
		}
		i++;
	}
	return (NULL);
}


/**
* _setenv - content of name env
* @name: variable env
* @value: value of variable
* Return: content of variable env or NULL
*/
void _setenv(char *name, char *value)
{
	int i = 0;
	unsigned int j;
	unsigned int k;

	while (environ[i] != NULL)
	{
		if (_strstr(environ[i], name))
		{
			j = 0;
			k = 0;
			while (name[j])
			{
				if (environ[i][j] == name[j])
					k++;
				j++;
			}
			if (k == _strlen(name))
			{
				_strcpy(_strstr(environ[i], name) + _strlen(name) + 1, value);
				break;
			}
		}
		i++;
	}
}
