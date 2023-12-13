#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork + wait +execve
 *
 * Return: 0
 */
int main(void)
{
	pid_t child_pid;
	int status;
	int i = 0;
	char *argv[] = {"/usr/bin/ls", "-l", "..", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		/** fork failed */
		if (child_pid == -1)
		{
			perror("Fork Error:");
			return (1);
		}
		/** fork success */
		else if (child_pid == 0)
		{
			/** run child first */
			/*printf("\n+++++++++++++");*/
			/**wait(&status);*/
			sleep(3);
			execve("/usr/bin/ls", argv, NULL);
			perror("Error:");
			/**sleep(3);*/
			exit(1);
		}
		else
		{
			/** run parent last */
			wait(&status);
			printf("+++++++++++++++++\n");
		}
	}

	return (0);
}
