#include "shell.h"
/**
 * main - the main SHELL function
 *
 * @argc: arguments counter
 * @argv: arguments victor from user
 * @envi: enviroment variables array
 *
 * Return: 0
 */
int main(int argc, char **argv, char **envi)
{
	bool interactive = (argc == 1 && isatty(STDIN_FILENO));

	prompt(argv, envi, interactive);
	return (0);
}

