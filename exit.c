#include "shell.h"

/**
 * _exit - function that terminate the prog when type "exit".
 *
 * @command: the command string to be read.
 *
 * Return: nothing.
 */
void _exit(char *command)
{
	if (_strcmp("exit", command) == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
}

