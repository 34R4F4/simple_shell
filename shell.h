#ifndef SHELL_H
#define SHELL_H

/** HEADERS */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>

/** CONSTANTS */
#define TOKENS 8

/** FUNCTIONS */
/* String Functions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
/* Operating Functions */
void prompt(char **arg_victor, char **env_list, bool run_mode);
char *trim(char *command);
char *_path(char **tokens_array, char *command);
void exe(char **tokens_array, char **arg_victor, char **env_list);
void ex_it(char *command);
/* External Functions */
extern char **environ;

#endif/*SHELL_H*/
