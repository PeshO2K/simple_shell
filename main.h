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

/*list.c*/
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
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
typedef struct
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
int execute_cmd(char **args,char **env);

/*strtok*/
char *my_strtok(char *str, const char *delim);
ssize_t my_getline(char **store, size_t *input_len, FILE *stream);
char **handle_separator(char *input);
char **split_string(char *str, int *num_words, char *delim);
char **parse(const char *cmd, const char *delim);
#endif
