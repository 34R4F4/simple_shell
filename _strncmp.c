#include "shell.h"

/**
 * _strncmp - compares n bytes from txt1 and txt2
 *
 * @txt1: first string
 * @txt2: second string
 * @n: number of bytes to be checked
 *
 * Return: 0 if success
 */
int _strncmp(char *txt1, char *txt2, int n)
{
	if (!n)
		return (0);

	if (*txt1 == *txt2)
		return (*txt1 ? _strncmp(txt1 + 1, txt2 + 1, n - 1) : 0);

	if (*txt1)
		return (1);
	if (*txt2)
		return (-1);

	return (*txt1 - *txt2);
}

