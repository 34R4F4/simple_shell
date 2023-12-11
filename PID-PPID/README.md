# PID & PPID

## PID process id
A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call `getpid` (`man 2 getpid`)

> pid.c

~~~
$ gcc -Wall -Werror -pedantic pid.c -o mypid && ./mypid
~~~

Note in the example above, that every time you run the program, a new process is created, and its ID is different.

Each process has a parent: the process that created it. It is possible to get the PID of a parent process by using the getppid system call (man 2 getppid), from within the child process.

## PPID parent process id

> ppid.c
~~~
$ gcc -Wall -Werror -pedantic ppid.c -o myppid && ./myppid
~~~
~~~
$ echo $$
~~~
they will be the same value, because it is the parent process id (the current working shell).

## PID_MAx
~
/proc/sys/kernel/pid_max
~
prints the maximum value a process ID can be

> pid_max.sh
~~~
$ chmod +x pid_max.sh
$ ./pid_max.sh
~~~
