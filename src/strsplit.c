#include <stdlib.h>
#include <stdio.h>
#include "str_func.h"

/**
* _strsplit - split string in tab_word
* @str: string
* @c: word delimiter
*
* Return: tab of word or NULL
*/

char **_strsplit(char *str, int c)
{
	unsigned int i, j, k;
	char **tab_word;

	if (str == NULL || _strlen(str) == 0)
		return (NULL);
	tab_word = malloc(sizeof(char *) * (_strlen(str)));
	if (tab_word == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] != c)
			j++;
		if (j == 0)
		{
			i++;
			continue;
		}
		tab_word[k] = malloc(sizeof(char) * _strlen(str) + 1);
		if (tab_word[k] == NULL)
		{
			for (j = 0; j < k; j++)
				free(tab_word[j]);
			free(tab_word);
			return (NULL);
		}
		for (j = 0; str[i + j] && str[i + j] != c; j++)
			;
		_strncpy(*(tab_word + k), (str + i), j);
		k++;
		i += j;
	}
	tab_word[k] = NULL;
	return (tab_word);
}
