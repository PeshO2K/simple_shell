#include "main.h"
/**
 * _getenv - finds environment variable
 *@name: env variable name
 *@vars: struct address
 * Return: NULL on failure ,pointer value success
 */
char *_getenv(var_t *vars, const char *name)
{
	/*printf("getting emvironment variable\n");*/
	char **s = vars->env;
	size_t len = strlen(name);

	/*printf("starting for loop...\n");*/

	for (; *s; s++)
	{
		if ((strncmp(name, *s, len) == 0) && ((*s)[len] == '='))
		{
			return (*s + len + 1);
		}
	}
	return (NULL);
}
/**
 *  * _getenv - finds environment variable
 *   *@name: env variable name
 *    *@vars: struct address
 *     * Return: NULL on failure pointer on sucess
 *      */
char **copyenv(char **env)
{
	char **newenv;
	int i,j;

	if (*env == NULL)
	{
		return (NULL);
	}

	for (i = 0; env[i]; i++)
	{
		;
	}


	newenv = malloc((i + 1) * sizeof(char *));
	if (newenv == NULL)
	{
		perror("newenv");
		return (NULL);
	}

	for (j = 0; j < i; j++)
	{
		newenv[j] = strdup(env[j]);
	}
	newenv[j] = NULL;

	return (newenv);



}
/**
 * _setenv - adds or changes environment variable
 * @name: env variable name
 * @value: new value
 * @overwrite: flag to overwrite existing value
 * Return: -1 on failure, 0 on success
 */
int _setenv(var_t *vars)
{
	/* make copies of name and value;
	 * use memcpy?
	 * malloc / calloc;
	 *
	 *
	 * if (!name || strlen(name) == 0 || strchr(name, '=') == 0)
	 * 	set errno = EINVAL;
	 * 	return (-1);
	 * If name exists && overwrite != 0:
	 * 	update value of name;
	 * elif (!name)
	 * 	add name;
	 * 	on error:
	 * 	set errno = ENOMEM;
	 * 	return (-1);
	 *
	 * return 0;
	 * */
	char *env_var, *curr_val;
	size_t name_len, value_len;

	/*Check for incorrect number of variables*/
	if (vars->argsc != 3)
	{
		print_error(vars, "Usage: setenv VARIABLE VALUE");
		return (-1);
	}
	/*printf("In setenv\n");*/
	name_len = strlen(vars->args[1]);
	value_len = strlen(vars->args[2]);

	/* if name is NULL or of zero length or contains '=' return error*/
	if (!(vars->args[1]) || (name_len == 0) || (strchr(vars->args[1], '=')))
	{
		/*printf("error here\n");*/
		/* set errno EINVAL here*/
		return (-1);
	}
	/*printf("Checking if variable exists\n");*/
	curr_val = _getenv(vars, vars->args[1]); /*return address of current value of name*/
	env_var = malloc(name_len + value_len + 2);
	memcpy(env_var, vars->args[1], name_len);
	env_var[name_len] = '=';
	memcpy(env_var + name_len + 1, vars->args[2], value_len);

	
	
	/*if found and values do not match, update*/
	if (curr_val && (strcmp(curr_val, vars->args[2]) != 0))
	{
		/*printf("It exists\n");*/
		/*update the row here and not the first address
		 * avoid pointer decay*/
		curr_val = curr_val - name_len - 1;
		memcpy(curr_val, env_var, name_len + value_len + 2);
		/* Handle error here
		 * return (-1);*/
	}/*The variable does not exist add it*/
	else if (!curr_val)
	{
		/*printf("does not exist. Add it..\n");*/
		/*use memcpy to do the thing
		 * strcat requires string to be stored in destination 
		 * assuming there's enough space
		 *
		 * Make an env_var and pass it to _putenv*/
		/*env_var = malloc(name_len + value_len + 2);*/
		/*trap memory allocation error here*/
		/*memcpy(env_var, vars->args[1], name_len);
		env_var[name_len] = '=';
		memcpy(env_var + name_len + 1, vars->args[2], value_len);*/

		_putenv(env_var, vars);/*add new env var*/
		/*Handle error here*/
		/*_my_env(vars);*/
	}
	

	return (0);
}
/**
 * _putenv - adds new element to the environment
 * @env_var: the variable to be added
 * Return: 0 on success, -1 on error.
 */
int _putenv(char *env_var, var_t *vars)
{
	size_t env_len, idx;
	char **new_env;
	

	/*printf("In _putenv\n");*/

	for (env_len = 0; vars->env[env_len]; env_len++)
	{
		;
	}
	/*printf("env_len: %lu\n", env_len);*/
	new_env = malloc((env_len + 2) * sizeof(char **));
	/*handle error here*/

	memcpy(new_env, vars->env, env_len * sizeof (char *));

	for (idx = 0; new_env[idx]; idx++)
	{
		;
	}
	/*printf("new_env length: %lu\n", idx);*/
	new_env[env_len] = env_var;
	new_env[env_len + 1] = NULL;

	vars->env = new_env;

	/*Increasing environement len by 1
	 * Adding to the end of the list.
	 * find the number of elements*/
	return (0);
}
/**
 * _unsetenv - deletes environment variable
 * @vars: struct containing variables
 * Return: 0 on success, -1 on error. 
 */
int _unsetenv(var_t *vars)
{
	char *curr_val;
	size_t env_len, idx = 0;

	/*printf("in unsetenv\n");*/


	if (vars->argsc != 2)
	{
		 print_error(vars, "Usage: unsetenv VARIABLE ");
		 return (-1);
	}

	curr_val = _getenv(vars, vars->args[1]);
	if (curr_val)
	{
		/* point to start of the string*/
		curr_val = curr_val - (strlen(vars->args[1])) - 1;
		for (env_len = 0; vars->env[env_len]; env_len++)
		{
			;
		}

		while(vars->env[idx] != curr_val)
		{
			
			/*rintf("env address: %p, ptr address: %p , curr_val address: %p\n", (void *)vars->env++, (void *)ptr, (void *)curr_val);
			printf("env: %s, ptr: %s\n\n", *(vars->env), *ptr);*/
			idx++;
		}
		
		for (; vars->env[idx]; idx++)
		{
			vars->env[idx] = vars->env[idx + 1];
		}

		/*printf("env_var at idx %lu: %s\n", idx, vars->env[idx]);*/
		
	}

	return (0);
}
