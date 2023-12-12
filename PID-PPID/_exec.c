#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"ls", "-l", "..", NULL};
    /**
     * argv[0]: command
     * argv[1]: command option
     * argv[2]: command target
     * argv[3]: command env
     */

    char *envv[] = {};

    printf("Before execve\n");
    if (execve("/usr/bin/ls", argv, envv) == -1)
	/** execve ( "command_path", argv, env) */
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
