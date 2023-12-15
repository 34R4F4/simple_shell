#include "shell.h"

/**
 * _strlen - function to get string length
 *
 * @txt: string
 *
 * Return: length of the string
 */
int _strlen(char *txt)
{
	int len = 0;

	while (*(txt + len) != '\0')
	{
		len++;
	}

	return (len);
}
