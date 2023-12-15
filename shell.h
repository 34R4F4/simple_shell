#ifndef SHELL_H
#define SHELL_H

/** Headers */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

/**
 * struct line - structure that contains line number
 * @cnt: lines cnt
 */
typedef struct line
{
	int cnt;
} line;

/** Functions */
void prompt(char **argv, char **envi, bool mode);
int _strcmp(char *txt1, char *txt2);
int _strlen(char *txt);
char *_strcpy(char *dist, char *src);
int _strncmp(char *txt1, char *txt2, int n);
char *_strncat(char *dist, const char *src, size_t n);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_trim(char *command);
void _exit(char *command);
void ctrlc(int num);
char *_path(char **argv, char *command);
int intlen(int n);
void geterror(denum *n, char **argv, char *command);

/** extern enviroment */
extern char **environ;

#endif /* SHELL_H */
