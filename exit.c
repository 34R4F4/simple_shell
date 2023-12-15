#include "shell.h"

/**
 * ex_it - function that terminate the prog when type "exit".
 *
 * @command: the command string to be read.
 *
 * Return: nothing.
 */
void ex_it(char *command)
{
	if (_strcmp("exit", command) == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
}

