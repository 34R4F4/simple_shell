 
# Everything you need to know to start coding your own shell
 
---

## PID & PPID

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

### command line to av
Write a function that splits a string and returns an array of each word of the string.

`man strtok`

> strtok.c

~~~
$ gcc strtok.c -o strtok
$ ./strtok
~~~

> _strtok.c

---

## Executing a program

The system call `execve` allows a process to execute another program (`man 2 execve`)

> exec.c

~~~
$ gcc -Wall -Wextra -Werror -pedantic exec.c -o exec
$ ./exec
~~~

~~~c
 char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
    /**
     * argv[0]: command path		bin/ls
     * argv[1]: command option		-l
     * argv[2]: command target		/usr/
     * argv[3]: command env		NULL
     */

 char *envv[] = {};	//NULL
 execve(argv[0], argv, envv);
 /** execve (command_path, argv, env) */
~~~

---

## Creating processes

The system call `fork` (`man 2 fork`) creates a new child process, almost identical to the parent (the process that calls `fork`). Once `fork` successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.

> fork.c

~~~
$ gcc fork.c -o fork
$ ./fork
~~~

Using the return value of fork, it is possible to know if the current process is the father or the child: 

	fork will return :
	 	0				to the child
	 	PID of the child 		to the father
	 	-1				if failuar

* code:
	- step1
	- step2
	- fork
	- step3
	- step4

* execusion:
	* parent
		- step1
		- step2
		- fork
		- step3
		- step4
	* child
		- step3
		- step4

---

## Wait

The `wait` system call (`man 2 wait`) suspends execution of the calling process until one of its children terminates.

> wait.c

~~~
$ gcc -Wall -Wextra -Werror -pedantic wait.c -o wait
$ ./wait 
~~~

* code:
   - step1
   - step2
   - fork
   - wait
   - step3
   - step4

* execusion:
	* parent
		- step1
		- step2
		- fork
		- wait
	* child
		- step3
		- step4
	* parent
		- step3
		- step4


---

### Exercise: fork + wait + execve

Write a program that executes the command `ls -l /tmp` in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.

> fork-wait-execve.c

~~~
$ gcc fork-wait-execve.c -o fwe
$ ./fwe
~~~

----

# Exercise: super simple shell

Using everything we saw, write a first version of a super simple shell that can run commands with their full path, without any argument.
* files:
 - env-environ.c
 - env-main.c
 - exec
 - exec.c
 - fork
 - fork.c
 - mypid
 - pid.c
 - ppid
 - ppid.c
 - printenv
 - prompt
 - promptc
 - prompt.c
 - shell.c
 - wait
 - wait.c

~~~
$ gcc -Wall -Werror -pedantic shell.c -o shell
$ ./shell
~~~

---
# Super Simple Shell

 write a first version of a super simple shell that can run commands with their full path, without any argument.
---

# File information

The `stat` (`man 2 stat`) system call 
 * gets the status of a file. 
	- Return	 0	On success
	- Return	-1	On error

> stat.c
---

## find a file in the PATH
Write a program that looks for files in the current PATH.
	Usage: `_which filename ...`

---
### access()

`int access(const char *path, int mode);`

   - `path`: The path to the file or directory whose accessibility is being checked.
   - `mode`: The access mode indicating the type of accessibility check. It can be a combination of the following flags:
	* R_OK: Check if the file is readable.
	* W_OK: Check if the file is writable.
	* X_OK: Check if the file is executable.
	* F_OK: Check if the file exists.

 Return:
	 0	success
	-1	fail


---

# Environment

We have seen earlier that the shell uses an environment list, where environment variables are “stored”. The list is an array of strings, with the following format: `var=value`, where `var` is the name of the variable and value its `value`. As a reminder, you can list the environment with the command `printenv`:

~~~
$ printenv
~~~

Actually, every process comes with an environment. When a new process is created, it inherits a copy of its parent’s environment. To access the entire environment within a process, you have several options:

    - via the `main` function
    - via the global variable `environ` (man environ)






<br>

===
***
---
