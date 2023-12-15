#include "shell.h"

/**
 * _itoa - function convert intger to string
 *
 * @num: the number to convert
 *
 * Return: the string text
 */
char *_itoa(int num)
{
	char *txt;
	size_t  n;
	int len = intlen(num);

	txt = malloc(len + 1);
	if (!txt)
	{
		return (NULL);
	}

	txt[len] = '\0';
	if (num < 0)
	{
		n = num * -1;
		*txt = '-';
	}
	else
	{
		n = num;
	}
	len--;

	do {
		*(txt + len) = (n % 10) + '0';
		n /= 10;
		len--;
	} while (n > 0);

	return (txt);
}
