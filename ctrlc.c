#include "shell.h"

/**
 * ctrlc - handle cntrl c
 *
 * @num: keyboard num argument
 */
void ctrlc(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
}
