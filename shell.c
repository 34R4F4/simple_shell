#include "shell.h"
/**
 * main - the main SHELL function
 * @argc: arguments counter
 * @arg_victor: arguments victor from user
 * @env_list: enviroment variables array
 * Return: 0
 */
int main(int argc, char **arg_victor, char **env_list)
{
	bool interactive = (argc == 1 && isatty(STDIN_FILENO));

	prompt(arg_victor, env_list, interactive);
	return (0);
}
