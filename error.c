#include "shell.h"

/**
 * geterror - function to handle error message
 *
 * @n: error line number
 * @argv: arguments victor
 * @command: the command.
 *
 * Return: void.
 */
void geterror(denum *n, char **argv, char *command)
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
