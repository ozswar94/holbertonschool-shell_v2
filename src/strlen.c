#include "str_func.h"

/**
* _strlen - determine sizeof ol string
* @s: string
* Return: the size of s
*/

unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
* _strlen_2d - determine sizeof of string 2d
* @s: string
* Return: the size of s
*/
unsigned int _strlen_2d(char **s)
{
	unsigned int i = 0;

	while (s[i])
		i++;
	return (i);
}
