#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/** main - main super_simple_shell function
 *
 * return: 0
 */

int main(void)
{
	char *buffer = NULL;	/*locla buffer to save stdin*/
	size_t bf_size = 0;	/*buffer size*/
	char *tok;		/*extracted arg from stdin buffer*/
	char **toks_arr;	/*args array from stdin buffer*/
	int t = 0;		/*strtok() counter*/
	pid_t child_pid;	/*command PID*/
	int status;		/*for waiting*/


while (1)/*start loop*/
{

/** initial prompt */

	write(1, "#cisfun$ ", 9);
	/*print charcters to the standad streams*/
	/** write (
	 * 	stream > stdout	=>	1
	 * 	string 		=>	"#cisfun$ "
	 *	string length 	=>	9
	 *	)
	 */


/** recicve prompt */
	
	getline(&buffer, &bf_size, stdin);
	/*save from stdin to the buffer*/
	/** getline (
	 * 	Buffer address		=>	&buffer
	 * 	Buffer-Size address	=>	&bf_size
	 * 	source	> stream	=>	stdin
	 * 	)
	 */


/** extract arguments */

	tok = strtok(buffer, "\t\n");
	/*convert string to array of tokens by separator*/
	/** strtok (
	 * 	string		=>	buffer
	 * 	separator	=>	"\t\n"
	 */

	toks_arr = malloc(sizeof(char) * 1024);
	/*array to contains all tokenized args*/

	while (tok)
	/*tokenize the while inputed*/
	{
		toks_arr[t] = tok;
		/*save token to the array*/
		tok = strtok(NULL, "\t\n");
		/*continue tokenizing the next*/
		t++;
	}
	toks_arr[t] = NULL;/*terminate the array*/
	t = 0;	/*reset incase of another input entered*/


/** manage processe */

	child_pid = fork();
	/*create sub-process to run inputed command*/

	/*fork fail*/
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}


/** execute command */

	/*fork sub-process success*/
	if (child_pid == 0)
	{
		if (toks_arr[0] == NULL)
			exit(1);

		if (execve(toks_arr[0], toks_arr, NULL) == -1)
		/** execve (
		 * 	execution file path	toks_arr[0]	/usr/bin/ls
		 * 	execution options	toks_arr	{
		 * 						command		"ls",
		 * 						options		"-l",
		 * 						target		"/tmp"
		 * 						env		NULL
		 * 						}
		 * 	environment		NULL
		 */
		{
			perror("Execution Error!");
		}
	}
	else
	{
		wait(&status);
		/*suspends execution of the calling process
		   until one of its children terminates.*/
	}


/* free memory */
	free(toks_arr);

}/*end while loop*/


return (0);
}
