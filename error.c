#include "shell.h"

/**
 *puts_stderr - prints an input string to send to stderr
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void puts_stderr(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		putchar_stderr(str[i]);
		i++;
	}
}


/**
 * putchar_stderr - writes characters from puts_stderr to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putchar_stderr(char c)
{
	static int i;
	static char buffer[WRITE_BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buffer[i++] = c;
	return (1);
}



/**
 * put_std - writes character c to a given std stream
 * @c: The character to print
 * @std: The filedescriptor to write to stdin/stdout/stderr
 *
 * Return: 1 On success,	-1 On error
 */
int put_std(char c, int std)
{
	static int i;
	static char buffer[WRITE_BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(std, buffer, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buffer[i++] = c;
	return (1);
}


/**
 *puts_std - prints an input string to std stream
 * @str: the string to be printed
 * @std: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int puts_std(char *str, int std)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += put_std(*str++, std);
	}
	return (i);
}
