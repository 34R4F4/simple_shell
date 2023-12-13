#include <stdio.h>
#include <unistd.h>

/**
 * main - my simple fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    int x = 1;

    printf("step-%d:\tPID%d\t%u\n", x++,x, getpid());
    printf("step-%d:\tPID%d\t%u\n", x++,x, getpid());
    fork();
    printf("step-%d:\tPID%d\t%u\n", x++,x, getpid());
    printf("step-%d:\tPID%d\t%u\n", x++,x, getpid());

    /** printf("PID%d\t%u\n", x++, getpid()); */
    
    return (0);
}
