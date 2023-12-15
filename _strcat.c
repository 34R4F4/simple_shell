#include "shell.h"

/**
 * _strcat - function adds src string to the dest string
 *
 * @dest: destination string to append to it
 * @src: source string to append from it
 *
 * Return: the updated dest string
 */
char *_strcat(char *dest, char *src)
{
	int lenc = _strlen(src);
	int lend = _strlen(dest);
	int j;

	for (j = 0; j < lenc; j++)
	{
		dest[lend + j] = src[j];
	}

	dest[lend + lenc] = '\0';
	return (dest);
}
