#include "shell.h"

/**
 * _strncpy - function to copy n chars from src to dest srtings
 *
 * @dest: destination string copy to it
 * @src: source string copy from
 * @n: number of characters to copy
 *
 * Return: updated destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
