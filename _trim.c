#include "shell.h"

/**
 * _trim - function to remove space from the command
 *
 * @command: command string
 *
 * Return: timmed command
 */
char *_trim(char *command)
{
	char *cpcmd;
	int len;
	int i = 0;

	while (command[i] == ' ')
		i++;

	len = _strlen(command) - i + 1;
	cpcmd = malloc(len + 1);
	if (!cpcmd)
	{
		perror("Memory Allocation Failed\n");
		return (NULL);
	}
	_strncpy(cpcmd, command + i, len);
	cpcmd[len] = '\0';
	_strcpy(command, cpcmd);

	free(cpcmd);
	return (command);
}
