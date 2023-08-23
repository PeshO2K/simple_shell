#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdbool.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \n\t\r\a"
#define VAR_INIT \
{NULL, NULL, 0, NULL, NULL, NULL, NULL, \
	0, 0, 0, 0}



/*list.c*/
/**
 * struct Node- singly linked list
 * @data: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct Node
{
	char *data;
	struct Node *next;
} Node;
/**
 * struct my_variables - variables
 * @line: buffer of command
 * @env: environment variables
 * @line_count: count of commands entered
 * @line_count_flag: if on count this line of input
 * @path : cmd_path
 * @args: arguments at opening of shell
 * @myname: the program filename
 * @rdfd: file descriptor
 * @err_num: error number
 * @PATH: a list of  path directories
 * @e_status: exit status
 */
typedef struct my_variables

{
	char *myname;
	char *line;
	int argsc;
	char **args;
	char **env;
	char *path;
	Node *PATH;
	unsigned int line_count;
	int line_count_flag;
	int err_num;
	int e_status;
/*	int rdfd;*/
} var_t;

Node *new_node(const char *data);
void add_node(Node **head, const char *data);
void print_list(Node *head);
void free_list(Node *head);
size_t list_len(const Node *head);

/*path.c*/
Node *build_path_list(var_t *vars);
char *find_file_in_path(var_t *vars);

/*builtin*/
/**
 * struct builtin_t - singly linked list
 * @name: function name
 * @func: function pointer
 *
 * Description: singly linked list node structure
 */
typedef struct builtin_t
{
	char *name;
	int (*func)(var_t *);
} builtin_t;

int _my_exit(var_t *vars);
int _my_cd(var_t *vars);
int _my_alias(var_t *vars);
int _my_setenv(var_t *vars);
int _my_unsetenv(var_t *vars);
int execute_builtin(var_t *vars);

/*environ.c*/
int _my_env(var_t *vars);
char *_getenv(var_t *vars, const char *name);
char **copyenv(char **env);
int _setenv(var_t *vars, char *name, char *value);
int _unsetenv(var_t *vars, char *name);
int _putenv(char *env_var, var_t *vars);

/*env_utils.c*/
int _chdir(var_t *vars, char *new_pwd);

/*handler.c*/
void _errputs(char *str);
void print_error(var_t *vars, char *emsg);
char *_uitoa(unsigned int num);
void print_unsigned_int(unsigned int n);


/*executor*/
int do_fork(var_t *vars);
int execute_cmd(var_t *vars);
int test_path(var_t *vars);


/*strtok*/
char *my_strtok(char *str, const char *delim);
char **parse(const char *cmd, const char *delim);
int _isalpha(char *s);
void *_memcpy(void *dest, void *src, size_t n);
char *_strdup(char *str);


/*removed*/
ssize_t my_getline(char **store, size_t *input_len, FILE *stream);
char **handle_separator(char *input);
char **split_string(char *str, int *num_words, char *delim);

/*memory.c*/
void ffree(char ***pp);

/*string.c*/
size_t _strlen(const char *s);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);
char *_strcpy(char *dest, char *src);

/*string2.c*/
char *_strchr(const char *s, int c);
/*char *_strcat(char *dest, char *src);*/
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/*utils.c*/
void sigintHandler(__attribute__((unused))int sig_num);
void free_vars(var_t *vars, int all);
void set_vars(var_t *vars, char **argv);
void reset_vars(var_t *vars);
int interactive(var_t *vars);

int shell_loop(var_t *vars,char **argv);
#endif
