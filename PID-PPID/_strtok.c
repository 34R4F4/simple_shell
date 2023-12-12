#include <stdio.h>


void _strtok(const char *str0, char separator)
{
	int len0 = strlen(str);
	char str1[len0 + 1];
	int a, b;

	for (a = 0; a <= len0; a++)
	{
		b = 0;
		if (str0[a] == separator || str0[a] == '\0')
			str1[b] = '\0';
		if (b > 0)
		
		{
			printf("%s\n", str1);
			b = 0;
		}
		else
		{
			str1[b] = str0[a];
			b++;
		}
	}
}
