#include "shell.h"
/**
 * trim - function to remove space from the command
 * @command: command string
 * Return: timmed command
 */
char *trim(char *command)
{
	char *command_copy;
	int i = 0, len;

	while (command[i] == ' ')
		i++;
	len = _strlen(command) - i + 1;
	command_copy = malloc(len + 1);
	if (!command_copy)
	{
		perror("Allocation Failed\n");
		return (NULL);
	}
	_strncpy(command_copy, command + i, len);
	command_copy[len] = '\0';
	_strcpy(command, command_copy);
	free(command_copy);
	return (command);
}
