#include <stdlib.h>
#include <string.h>

extern char **environ;

int my_setenv(const char *name, const char *value, int overwrite) {
	int index = 0;
	size_t len = strlen(name);
	for (char **env = environ; *env != 0; env++) 
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=') 
		{
			if (overwrite) 
			{
				size_t val_len = strlen(value);
				char *new_env = malloc(len + val_len + 2);
				if (new_env == NULL) 
				{
					return -1;
				}
				memcpy(new_env, name, len);
				new_env[len] = '=';
				memcpy(new_env + len + 1, value, val_len);
				new_env[len + val_len + 1] = '\0';
				*env = new_env;																            }
			 return 0;
		 }
		index++;
	}
	
	char **new_environ = malloc((index + 2) * sizeof(char *));
	if (new_environ == NULL) 
	{
		return -1;
	}
	
	memcpy(new_environ, environ, index * sizeof(char *));
	size_t val_len = strlen(value);
	char *new_env = malloc(len + val_len + 2);
	
	if (new_env == NULL) 
	{
		free(new_environ);
		return -1;
	}
	memcpy(new_env, name, len);
	new_env[len] = '=';
	memcpy(new_env + len + 1, value, val_len);
	new_env[len + val_len + 1] = '\0';
	
	new_environ[index] = new_env;
	new_environ[index + 1] = NULL;
	environ = new_environ;
	return 0;
}


#include <stdlib.h>
#include <string.h>

extern char **environ;

int my_unsetenv(const char *name) {
	int index = 0;
	size_t len = strlen(name);
	for (char **env = environ; *env != 0; env++) 
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			for (char **e = env; *e != 0; e++) 
			{
				*e = *(e + 1);
			}
			return 0;
		}
		index++;
	}
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	char *home = getenv("HOME");
	char *oldpwd = getenv("OLDPWD");
	char *pwd = getenv("PWD");
	if (argc == 1) {
		chdir(home);
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", home, 1);
	} else if (strcmp(argv[1], "-") == 0) {
								            if (oldpwd != NULL) {
										                chdir(oldpwd);
												            setenv("OLDPWD", pwd, 1);
													                setenv("PWD", oldpwd, 1);
															        }
									        } else {
											        chdir(argv[1]);
												        setenv("OLDPWD", pwd, 1);
													        setenv("PWD", argv[1], 1);
														    }
			    return 0;
}

