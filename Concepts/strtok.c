#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *str0 = "Hello I am Arafa ! I'am Soft-Ware Engineer.";
	int len0 = strlen(str0);
	char *str1 = malloc(sizeof(char) * len0);
	char separator[] = " ";
	char *cuts;
	int i;

	strcpy(str1, str0);
	cuts = strtok(str1, separator);

	while (cuts != NULL)
	{
		printf("%s\n", cuts);
		cuts = strtok(NULL, separator);
	}

	for (i = 0; i < len0; i++)
	{
		if (str1[i] == '\0')
			printf("\\0");
		else
			printf("%c", str1[i]);
	}

	return (0);
}
