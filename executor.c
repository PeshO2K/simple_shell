#include "main.h"

/**
 */
int execute_cmd(char **args,char **env)
{
	int status;
	pid_t child_pid;
/*	char *filepath;
*	
	if (strncmp(args[0], "/", 1) != 0)
	{
	
		if (execute_builtin(args) == -1)
	
		{
		
			filepath = find_file_in_path(args[0]);

			printf("%s\n",filepath);
	
		}
	}
	else
	{
		filepath = args[0];
	}*

	if (filepath)
	{*
	
		args[0] = filepath;*/
		child_pid = fork();

		if (child_pid == 0)
		{
			if(execve(args[0],args, env) == -1)
			{
				printf("Nikona error");
				perror("Error: ");
			}
		}
		else if (child_pid < 0)
		{
			printf("No forking");
		}
		else
		{
			wait(&status);
			return(0);
		}
	
	

	return(-1);

}
