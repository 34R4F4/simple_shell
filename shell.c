#include "shell.h"
/**
 * main - main super_simple_shell function
 *
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t bf_size = 0;
	char *tok;
	char **toks_arr;
	int t = 0;
	pid_t child_pid;
	int status;

while (1)
{
	write(1, "#cisfun$ ", 9);
	getline(&buffer, &bf_size, stdin);
	tok = strtok(buffer, "\t\n");
	toks_arr = malloc(sizeof(char) * 1024);
	while (tok)
	{
		toks_arr[t] = tok;
		tok = strtok(NULL, "\t\n");
		t++;
	}
	toks_arr[t] = NULL;
	t = 0;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		if (toks_arr[0] == NULL)
			exit(1);
		if (execve(toks_arr[0], toks_arr, NULL) == -1)
			perror("Execution Error!");
	}
	else
		wait(&status);
	free(toks_arr);
}
return (0);
}
