#include <stdlib.h>
#include <stdio.h>

/**
 * print_args - function print arguments without using ac
 * @argc: args count
 * @argv: args value
 * Return: void
 */

int main(int argc, char **argv)
{
	(void)argc;

	while (*argv != NULL)
	{
		printf("argv:\t%s\n", *argv);
		argv++;
	}
	return (0);
}
