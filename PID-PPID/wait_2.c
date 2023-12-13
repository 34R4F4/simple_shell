#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    int status;
    int x = 1;

    printf("step-%d:\tPID%d\t%u\n", x++,x, getpid());
    printf("step-%d:\tPID%d\t%u\n", x++,x, getpid());
    fork();
    sleep(3);
    printf("step-%d:\tPID%d\t%u\n", x++,x, getpid());
    wait(&status);
    printf("step-%d:\tPID%d\t%u\n", x++,x, getpid());
    return (0);
}
