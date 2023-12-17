#include "shell.h"

/**
 * main - start Shell main function
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int std = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (std)
		: "r" (std));

	if (ac == 2)
	{
		std = open(av[1], O_RDONLY);
		if (std == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				puts_stderr(av[0]);
				puts_stderr(": 0: Can't open ");
				puts_stderr(av[1]);
				putchar_stderr('\n');
				putchar_stderr(BUFF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->read_std = std;
	}
	populate_env_list(info);
	log_read(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
