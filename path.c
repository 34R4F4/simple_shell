#include "shell.h"

/**
 * _path - handle the path function
 *
 * @tokens_array: tokenized command
 * @command: the command_buffer to save
 *
 * Return: command for execution
 */
char *_path(char **tokens_array, char *command)
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
		tokens_array[0] = _strcat(path, command);
		return (tokens_array[0]);
	}
	free(path);
	return (command);
}
