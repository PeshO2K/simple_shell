#include "main.h"

int main(int ac  __attribute__((unused)),char **ag __attribute__((unused)))
{
	/*size_t chars;*/
	char *line,*filepath;
	size_t line_size = 0;
	char **args;
	/*pid_t cpid;*/
	int int_mode = 1;

	while(int_mode)
	{
		int_mode = isatty(STDIN_FILENO);

		if (int_mode)
		{
			printf("$ ");
		}
	

		getline(&line, &line_size, stdin);
		/*printf("getline successful\n");*/
		args = handle_separator(line);
		/*printf("Printing arg[0]: %s\n",args[0]);
		for (int i = 0; args[i] != NULL; i++)
        	{
                	printf("%s\n", args[i]);
	        }*/
		if (strncmp(args[0], "/", 1) == 0)
		{
			filepath = args[0];
		}
		else
		{
			/*printf("\nAfter compare\n");*/
			if (execute_builtin(args) == -1)
			{
				filepath = find_file_in_path(args[0]);
				args[0] = filepath;
				/*printf("%s\n",filepath);*/
			}
			else
			{
				filepath = NULL;
			}
		}	
		if (filepath)
		{
			execute_cmd(args, environ);
		}
		/*free(line);*/
		free(filepath);
		free(args);
	}
	return (0);
}
