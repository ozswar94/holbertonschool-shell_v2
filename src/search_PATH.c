#include <stdlib.h>
#include <sys/stat.h>
#include "shell.h"
#include "printf.h"

/**
* free_dptr - free a pointer to pointer
* @ptr: pointer
*
*/
void free_dptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}


/**
* search_path - search in PATH env variable
* @command: name of command to search
*
* Return: absolute path of command or NULL if not found
*/
char *search_path(char *command)
{
	int i;
	struct stat buf;
	char *command_path = NULL;
	char **path_directory = NULL;

	if (_strchr(command, '/') != NULL)
	{
		command_path = _strdup(command);
		if (command_path == NULL)
			return (NULL);

		if (stat(command_path, &buf) == 0)
			return (command_path);
		return (NULL);
	}

	path_directory = _strsplit(_getenv("PATH"), ':');
	if (path_directory == NULL)
		return (NULL);

	i = 0;
	while (path_directory[i] != NULL)
	{
		command_path = malloc(_strlen(command) + _strlen(path_directory[i]) + 2);
		if (command_path == NULL)
			return (NULL);

		_strcpy(command_path, path_directory[i]);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		if (stat(command_path, &buf) == 0)
		{
			free_dptr(path_directory);
			return (command_path);
		}
		free(command_path);
		i++;
	}
	free_dptr(path_directory);
	return (NULL);
}
