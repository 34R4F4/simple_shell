#include "shell.h"

/**
 * _strcmp - function to compare two strings
 *
 * @txt1: first string
 * @txt2: second string
 *
 * Return: 0 if success
 */
int _strcmp(char *txt1, char *txt2)
{
	int diff = 0;

	while (*txt1 == *txt2 && *txt1 != '\0')
	{
		txt1++;
		txt2++;
	}

	if (txt1 != txt2)
	{
		diff = *txt1 - *txt2;
	}

	return (diff);
}
