#include <stdlib.h>
#include "str_func.h"

/**
 * _getnbr - print numbers (as char)
 * @nb: number to print
 *
 * Return: str as int
 */

char *_getnbr(int nb)
{
	char *str;
	int i;
	int n;

	str = malloc(sizeof(char) * 20);
	if (str == NULL)
		return (NULL);

	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		i++;
		nb *= -1;
	}
	for (n = 1; n <= nb / 10; n *= 10)
		;

	while (n > 0)
	{
		str[i] = (nb / n) + '0';
		i++;
		nb %= n;
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

