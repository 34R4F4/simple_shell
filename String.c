#include "shell.h"

/**
 * _strlen - length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcpy - copy a string
 * @dest: dest string arg
 * @src: source arg
 * Return: string value
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int len = _strlen(src);

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncpy - copy n char
 * @dest: string argument
 * @src: string argument for src
 * @n: integer argument
 * Return: dest
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

/**
 * _strcat - This function appends the src string to the dest string
 * @dest: string agument
 * @src: string argument
 * Return: String
 */
char *_strcat(char *dest, char *src)
{
	int len = _strlen(src);
	int lend = _strlen(dest);
	int j;

	for (j = 0; j < len; j++)
	{
		dest[lend + j] = src[j];
	}
	dest[lend + len] = '\0';
	return (dest);
}

/**
 * _strcmp - unction that compares two strings
 * @s1: first function
 * @s2: second function
 * Return: val
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0;

	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (s1 != s2)
		cmp = *s1 - *s2;

	return (cmp);
}
