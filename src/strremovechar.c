#include "str_func.h"


/**
* removeChar - remove char in string
* @str: ptr command
* @garbage: string line
*/
void removeChar(char *str, char garbage)
{
	char *src, *dst;

	if (!str)
		return;
	for (src = dst = str; *src != '\0'; src++)
	{
		*dst = *src;
		if (*dst != garbage)
			dst++;
	}
	*dst = '\0';
}
