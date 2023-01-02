#include "str_func.h"

/**
* _strncat - concataine 2 strings
* @dest: string
* @src: string
* @n: start copy
* Return: dest
*/

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
