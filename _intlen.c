#include "shell.h"

/**
 * intlen - funcion to get intger length
 *
 * @n: the number
 *
 * Return: the lenth.
 */
int intlen(int n)
{
	unsigned int num;
	int len = 1;

	if (n < 0)
	{
		len++;
		num = n * -1;
	}
	else
	{
		num = n;
	}
	while (num > 9)
	{
		len++;
		num = num / 10;
	}

	return (len);
}
