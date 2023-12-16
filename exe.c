#include "shell.h"

/**
 * exe - function to run command
 * @tokens_array: tokens array list
 * @arg_victor: argument victor
 * @env_list: eenviroment variables array
 */
void exe(char **tokens_array, char **arg_victor, char **env_list)
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

		if (execve(tokens_array[0], tokens_array, env_list) == (-1))
		{
			/* handle Error */
			write(STDOUT_FILENO, arg_victor[0], _strlen(arg_victor[0]));
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
