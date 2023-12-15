#include "shell.h"

/**
 * exe - function to run command
 *
 * @tokens_array: tokens_array argument
 * @argv: argument victor
 * @envi: enviroment variables array
 */
void _exe(char **tokens_array, char **argv, char **envi)
{
	pid_t child_PID;
	int status;

	child_PID = fork();

	if (child_PID == -1)
	{
		perror("Process Error");
		exit(EXIT_FAILURE);
	}
	if (child_PID == 0)
	{

		if (execve(tokens_array[0], tokens_array, envi) == (-1))
		{
			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, ": No such file or directory",
			_strlen(": No such file or directory"));
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}

