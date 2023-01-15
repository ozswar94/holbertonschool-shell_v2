#include <stdlib.h>
#include "str_func.h"
#include "printf.h"

/**
* _strdup - create a new string and copy str in the new string
* @str: string
* Return: new string
*/

char *_strdup(char *str)
{
	unsigned int size;
	char *buffer;

	if (str == NULL)
		return (NULL);
	for (size = 0; str[size] != '\0' ; size++)
	;

	buffer = (char *)malloc(sizeof(char) * size + 1);
	if (!buffer)
		return (NULL);

	_strcpy(buffer, str);

	return (buffer);
}

