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

/** Structures */
/**
 * struct line - structure that contains line number
 * @cnt: lines cnt
 */
typedef struct line
{
	int cnt;
} line;

/* Constansts */
#define TOKENS 10


/** Functions */
void prompt(char **argv, char **envi, bool mode);
int _strcmp(char *txt1, char *txt2);
int _strlen(char *txt);
char *_strcpy(char *dist, char *src);
int _strncmp(char *txt1, char *txt2, int n);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_trim(char *command);
void ex_it(char *command);
void ctrlc(int num);
char *_path(char **tokens_array, char *command_buffer);
void _exe(char **tokens_array, char **argv, char **envi);

/** extern enviroment */
extern char **environ;

#endif /* SHELL_H */
