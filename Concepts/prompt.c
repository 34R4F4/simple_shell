#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t buf_size = 0;
	char *buffer = NULL;

	/**
	 * buffer = malloc(sizeof(char) * 10);
	 * getline() reallocate the needed moemory
	 * */
	printf("$ ");
	getline(&buffer, &buf_size, stdin);
	printf("%s", buffer);



	free(buffer);

	return (0);
}