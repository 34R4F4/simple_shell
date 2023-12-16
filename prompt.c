#include "shell.h"

/**
 * CtrlC - handle Ctrl+C
 * @key: keyboard key press
 */
void CtrlC(int key)
{
	(void)key;
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
}

/**
 * prompt - shell prompt to recive command_buffers
 * @arg_victor: arguments victor
 * @env_list: envirement variable list
 * @run_mode: flag argument for mode (interactive/non-interactive)
 */
void prompt(char **arg_victor, char **env_list, bool run_mode)
{
	size_t buffer_size = 0;
	ssize_t key_c = 0;
	char *command_buffer = NULL;
	char *tokens_array[TOKENS];
	int t;

	while (1)
	{
		if (run_mode && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		signal(SIGINT, CtrlC);
		key_c = getline(&command_buffer, &buffer_size, stdin);

		/* [Ctrl+D] EOF */
		if (key_c == -1)
		{
			free(command_buffer);
			exit(EXIT_SUCCESS);
		}
		if (command_buffer[key_c - 1] == '\n')
			command_buffer[key_c - 1] = '\0';
		command_buffer = trim(command_buffer);
		if (_strlen(command_buffer) == 0)
			continue;
		t = 0;
		tokens_array[t] = strtok(command_buffer, " \n");
		ex_it(command_buffer);
		_path(tokens_array, command_buffer);
		while (tokens_array[t])
		{
			t++;
			tokens_array[t] = strtok(NULL, " \n");
		}
		exe(tokens_array, arg_victor, env_list);
	}
	free(command_buffer);
}
