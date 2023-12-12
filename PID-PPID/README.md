# PID & PPID

## PID process id
A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call `getpid` (`man 2 getpid`)

> pid.c

~~~
$ gcc -Wall -Werror -pedantic pid.c -o mypid && ./mypid
~~~

Note in the example above, that every time you run the program, a new process is created, and its ID is different.

Each process has a parent: the process that created it. It is possible to get the PID of a parent process by using the getppid system call (`man 2 getppid`), from within the child process.

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

`
/proc/sys/kernel/pid_max
`
prints the maximum value a process ID can be

> pid_max.sh

~~~
$ chmod +x pid_max.sh
$ ./pid_max.sh
~~~

---

## Arguments

The command line arguments are passed through the main function: `int main(int ac, char **av);`

  - `av` is a `NULL` terminated array of strings
  - `ac` is the number of items in `av`

`av[0]` usually contains the name used to invoke the current program.
`av[1]` is the first argument of the program, `av[2]` the second, and so on.

### av

> print_args.c

Write a program that prints all the arguments, without using ac.

~~~
$ gcc print_args.c -o print_args
$ ./print_args arg1 arg2 arg3
~~~

###  Read line

Write a program that prints "$ ", wait for the user to enter a command, prints it on the next line.

`man 3 getline`

Write your own version of `getline`

> prompt.c

~~~
$ gcc -Wall -Wextra -Werror -pedantic prompt.c -o prompt
$ ./prompt
~~~

<br>

===
***
---