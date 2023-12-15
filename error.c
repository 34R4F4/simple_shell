#include "shell.h"

/**
 * intlen - funcion to get intger length
 *
 * @n: the number
 *
 * Return: the lenth.
 */
int intlen(int n)
{
	unsigned int num;
	int len = 1;

	if (n < 0)
	{
		len++;
		num = n * -1;
	}
	else
	{
		num = n;
	}
	while (num > 9)
	{
		len++;
		num = num / 10;
	}

	return (len);
}

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

/**
 * geterror - function to handle error message
 *
 * @n: error line number
 * @argv: arguments victor
 * @command: the command.
 *
 * Return: void.
 */
void geterror(line *n, char **argv, char *command)
{
	int len;
	char *errmsg;
	char *line_no;

	line_no = _itoa(n->cnt);

	len = _strlen(argv[0]) + _strlen(command) + _strlen(line_no) + 17;
	errmsg = malloc(len);
	if (!errmsg)
	{
		return;
	}
	_strcpy(errmsg, argv[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, line_no);
	_strcat(errmsg, ": ");
	_strcat(errmsg, command);
	_strcat(errmsg, ": not found\n");
	_strcat(errmsg, "\0");
	write(STDOUT_FILENO, errmsg, len);
	free(errmsg);
}
