#ifndef SHELL_H
#define SHELL_H

/** HEADERS */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>


/** CONSTANTS */

/* BUFFER */
#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1

/* COMMAND CHAIN */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* CONVERT */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* USE SYSTEM'S */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* HISTORY */
#define LOG_FILE	".log"
#define LOG_SIZE	4096


/** STRUCTURES */

/**
 * struct liststr - single linked list num,str
 * @num: field number
 * @str: the field string
 * @next: ptr points to the next node, NULL ended
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a functions
 *@arg: string generated from getline containing arguements
 *@argv: arguments victor array of strings generated from arg
 *@path: path string of current command
 *@argc: the argument count
 *@line: the error count line
 *@err_num: the error code for exit()s
 *@ln_flag: if on, count this line of input
 *@file_name: the program filename
 *@env: linked list local copy of environ list
 *@environ: modified custom copy of environ from LL env
 *@history: history log
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buff: address of pointer to cmd_buff, on if chaining
 *@cmd_buff_type: CMD_type normal or ||, &&, ;(chain)
 *@read_std: the file discriptor std stream from which to read line input
 *@logs: history log recordline number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line;
	int err_num;
	int ln_flag;
	char *file_name;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buff;
	int cmd_buff_type; /* CMD_type || or  && or ;=>chain*/
	int read_std;
	int logs;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - execute hsh builtin functions
 *@type: the builtin command flag
 *@func: the function to execute
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/** EXTERNAL FUNCTIONS */
extern char **environ;


/** FUNCTIONS */

/* error.c */
void puts_stderr(char *);
int putchar_stderr(char);
int put_std(char c, int std);
int puts_std(char *str, int std);

/* builtin.c */
int hsh_exit(info_t *);
int hsh_cd(info_t *);
int hsh_help(info_t *);
int hsh_history(info_t *);

/* alias.c */
int hsh_alias(info_t *);
int set_alias(info_t *info, char *str);
int unset_alias(info_t *info, char *str);
int print_alias(list_t *node);

/* info.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* chain.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* list.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list_str(const list_t *);
size_t print_list(const list_t *);
void free_list(list_t **);

/* liststr.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
int delete_node_at_index(list_t **, unsigned int);

/* log.c */
char *get_log_file(info_t *info);
int log_write(info_t *info);
int log_read(info_t *info);
int log_add(info_t *info, char *buf, int linecount);
int log_renumber(info_t *info);

/* hsh.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_command(info_t *);
void fork_command(info_t *);

/* memory.c */
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void free_str(char **);
int free_ptr(void **);

/* getline.c */
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* env1.c */
char *_getenv(info_t *, const char *);
int hsh_env(info_t *);
int hsh_setenv(info_t *);
int hsh_unsetenv(info_t *);
int populate_env_list(info_t *);

/* env2.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* str1.c */
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strncat(char *, char *, int);
char *_strcpy(char *, char *);
char *_strncpy(char *, char *, int);

/* path.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* print.c */
void _puts(char *);
int _putchar(char);

/* strtow.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* str2.c */
int _strlen(char *);
char *_strdup(const char *);
char *starts_with(const char *, const char *);
char *_strchr(char *, char);

/* func1.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* func2.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_digit(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* SHELL_H */
#endif
