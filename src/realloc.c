#include <stdlib.h>
#include "str_func.h"

/**
* _realloc - re-alloc a ptr
* @ptr: pointer reallocated
* @old_size: old size of ptr
* @new_size: new size of ptr
* Return: ptr re-alloc
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	unsigned char *buffer;
	unsigned char *ptr_tmp;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
	{
		ptr = (unsigned char *)malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr_tmp = (unsigned char *)ptr;
	buffer = (unsigned char *)malloc(new_size);
	if (buffer == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		*(buffer + i) = *(ptr_tmp + i);
	free(ptr);

	return ((void *)buffer);
}

