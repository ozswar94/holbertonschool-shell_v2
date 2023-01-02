#include <stdlib.h>
#include "str_func.h"


/**
* _atoi - string to int
* @str: string
*
* Return: number
*/
int _atoi(const char *str)
{
	int i;
	int nbr;
	int unit;

	if (str == NULL)
		return (0);
	nbr = 0;
	unit = 1;
	i = 0;
	while (str[i + 1])
	{
		if (_isalpha(str[i]) == 1)
			return (-1);
		unit *= 10;
		i++;
	}
	i = 0;
	while (str[i])
	{
		nbr += (str[i] - '0') * unit;
		unit /= 10;
		i++;
	}
	return (nbr);
}
