#include "main.h"
/**
  * build_path_list - list path directories
  * @vars: global variables struct
  *
  * Return: pointer to head
  */
Node *build_path_list(var_t *vars)
{
	char *PATH =  _getenv(vars, "PATH");
	Node *head = NULL;

	if (PATH)
	{
	char *path_cpy = _strdup(PATH);
	char *token = my_strtok(path_cpy, ":");


	while (token)
	{
		add_node(&head, token);
		token = my_strtok(NULL, ":");
	}
	free(path_cpy);
	}
	return (head);
}

/**
  * find_file_in_path - finds file path
  * @vars: struct address
  * Return: NULL or the full path
  */
char *find_file_in_path(var_t *vars)
{
	Node *cursor = vars->PATH;
	size_t full_path_len;
	char *full_path, *filename = vars->args[0];

	while (cursor)
	{
		DIR *dir = opendir(cursor->data);

		if (dir)
		{
			struct dirent *entry;

			while ((entry = readdir(dir)))
			{
				if (_strcmp(entry->d_name, filename) == 0)
				{
					closedir(dir);

					/*size_t full_path_len;*/

					full_path_len = _strlen(cursor->data) + _strlen(filename) + 2;
					full_path = malloc(full_path_len);

					_strncpy(full_path, cursor->data, full_path_len);
					_strncat(full_path, "/", full_path_len - _strlen(full_path));
					_strncat(full_path, filename, full_path_len - _strlen(full_path));
					return (full_path);
				}
			}
			closedir(dir);
		}
		cursor = cursor->next;
	}
	return (NULL);
}
