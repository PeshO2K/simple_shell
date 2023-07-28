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

#define DELIM " \n\t\r\a"

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

Node *new_node(const char *data);
void add_node(Node **head, const char *data);
void print_list(Node *head);
void free_list(Node *head);
size_t list_len(const Node *head);

/*path.c*/
Node *build_path_list(void);
char *find_file_in_path(char *filename);


/*environ.c*/
extern char **environ;
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

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
	int (*func)(char **);
} builtin_t;

int _my_exit(char **ag);
int _my_env(char **ag);
int _my_cd(char **ag);
int _my_alias(char **ag);
int execute_builtin(char **ag);
/*helper functions*/
int _putchar(char);

/*executor*/
int do_fork(char **args, char **env);
int execute_cmd(char **args, char **env);

/*strtok*/
char *my_strtok(char *str, const char *delim);
ssize_t my_getline(char **store, size_t *input_len, FILE *stream);
char **handle_separator(char *input);
char **split_string(char *str, int *num_words, char *delim);
char **parse(const char *cmd, const char *delim);

/*string.c*/
int _strlen(char *s);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);
char *_strcpy(char *dest, char *src);

/*string2.c*/
char *_strchr(char *s, char c);
/*char *_strcat(char *dest, char *src);*/
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
#endif
