#include "main.h"
/**
 * main - Entry point
 * @ac: number of arguments
 * @ag: argument vector
 * Return: 0 Success
 */
int main(int ac __attribute__((unused)), char **ag __attribute__((unused)))
{
	char *line, *filepath = NULL;
	size_t line_size = 0;
	char **args;
	int int_mode, i = 0, status = 1; /* i;*/
	FILE *fp;

	int_mode = isatty(STDIN_FILENO);
	if (int_mode)
	{
		while (status)
		{
			printf("# ");
			/*printf("loop: %d\n",i);*/
			my_getline(&line, &line_size, stdin);
			if (feof(stdin))
			{
				break;
			}
			args = parse(line, DELIM);
			status = execute_cmd(args, environ);

			/*free(line);*/
			free(filepath);
			free(args);
			i++;
		}
	}
	else
	{
		while (my_getline(&line, &line_size, stdin) != -1)
		{
			line[strcspn(line, "\n")] = 0;
			fp = popen(line, "r");
			if (fp == NULL)
			{
				perror("Failed to run command");
				exit(1);
			}
			while (my_getline(&line, &line_size, fp) != -1)
			{
				printf("%s\n", line);
			}
			pclose(fp);
		}
	}
	return (0);
}
