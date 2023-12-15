#include "shell.h"

/**
 * _strcpy - function to copy a string to another
 *
 * @dist: the copy
 * @src: source string
 *
 * Return: the string copy
 */
char *_strcpy(char *dist, char *src)
{
	int i, len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dist[i] = src[i];
	}

	dist[i] = '\0';
	return (dist);
}
