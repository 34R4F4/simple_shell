#include "shell.h"

/**
 * _path - handle the path function
 *
 * @argv: argument victor
 * @command: inputed command
 *
 * Return: command for execution
 */
char *_path(char **argv, char *command)
{
	char *path;

	path = malloc(_strlen("/bin/") + _strlen(command) + 1);

	if (!path)
	{
		return (NULL);
	}
	_strcpy(path, "/bin/");

	if (command[0] != '/' && command[0] != '.')
	{
		argv[0] = _strcat(path, command);
		return (argv[0]);
	}
	free(path);
	return (command);
}
