#include "shell.h"

/**
 * prompt - a shell prompt to recive commands
 *
 * @argv: arguments victor
 * @envi: envirement variable argument
 * @mode: flag argument for mode (interactive/non-interactive)
 */
void prompt(char **argv, char **envi, bool mode)
{
	size_t buffer_size = 0;
	ssize_t num_c = 0;/* keyboard_input*/
	char *command_buffer = NULL;
	char **tokens_array;
	int t;

	while (1)
	{
		if (mode && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		signal(SIGINT, ctrlc);
		num_c = getline(&command_buffer, &buffer_size, stdin);
		if (num_c == -1) /*handles EOF 'Ctrl+D'*/
		{
			free(command_buffer);
			exit(EXIT_SUCCESS);
		}
		if (command_buffer[num_c - 1] == '\n')
			command_buffer[num_c - 1] = '\0';
		command_buffer = trim(command_buffer);
		if (_strlen(command_buffer) == 0)
			continue;
		t = 0;
		tokens_array[t] = strtok(command_buffer, " \n");
		_exit(command_buffer);
		_path(tokens_array, command_buffer);
		while (tokens_array[t])
		{
			t++;
			tokens_array[t] = strtok(NULL, " \n");
		}
		exe(argv, tokens_array, envi); /* envir */
	}
	free(command_buffer);
}
