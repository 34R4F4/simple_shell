#include "shell.h"

/**
 * _strncat - join two strings (dist + n bytes from src)
 *
 * @dist: Pointer of the destination string.
 * @src: Pointer of the source string.
 * @n: bytes to copy from src.
 *
 * Return: Pointer of updated destination string.
 */
char *_strncat(char *dist, const char *src, size_t n)
{
	size_t dist_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dist[dist_len + i] = src[i];
	}
	dist[dist_len + i] = '\0';

	return (dist);
}

