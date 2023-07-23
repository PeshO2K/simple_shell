#include "main.h"
Node *build_path_list(void)
{
	char *PATH = _getenv("PATH");
	char *path_cpy = strdup(PATH);
	char *token = strtok(path_cpy, ":");

	Node *head = NULL;

	while (token)
	{
		add_node(&head, token);
		token = strtok(NULL, ":");
	}
	free(path_cpy);
	return (head);
}

char *find_file_in_path(Node *head, char *filename)
{
	Node *cursor = head;

	while (cursor)
	{
		DIR *dir = opendir(cursor->data);

		if (dir)
		{
			struct dirent *entry;

			while ((entry = readdir(dir)))
			{
				if (strcmp(entry->d_name, filename) == 0)
				{
					closedir(dir);
					size_t full_path_len = strlen(cursor->data) + strlen(filename) + 2;
					char *full_path = malloc(full_path_len);
					strncpy(full_path, cursor->data, full_path_len);
					strncat(full_path, "/", full_path_len - strlen(full_path));
					strncat(full_path, filename, full_path_len - strlen(full_path));
					return (full_path);
				}
			}
			closedir(dir);
		}
		cursor = cursor->next;
	}
	return (NULL);
}
