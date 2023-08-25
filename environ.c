#include "main.h"
/**
 * _getenv - finds environment variable
 * @name: env variable name
 * @vars: struct address
 * Return: NULL on failure ,pointer value success
 */
char *_getenv(var_t *vars, const char *name)
{
	char **s = vars->env;
	size_t len = _strlen(name);

	for (; *s; s++)
	{
		if ((_strncmp(name, *s, len) == 0) && ((*s)[len] == '='))
		{
			return (*s + len + 1);
		}
	}
	return (NULL);
}
/**
 * copyenv - copy environment
 * @env: environment
 * Return: NULL on failure pointer on sucess
 */
char **copyenv(char **env)
{
	char **newenv;
	int i, j, k;

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
		newenv[j] = _strdup(env[j]);
		if (!(newenv[j]))
		{
			for (k = 0; k < j; k++)
			{
				free(newenv[k]);
			}
			free(newenv);
			return (NULL);
		}
	}
	newenv[j] = NULL;
	return (newenv);
}
/**
 * _setenv - adds or changes environment variable
 * @vars: global variables struct
 * @name: env variable name
 * @value: new value
 * Return: -1 on failure, 0 on success
 */
int _setenv(var_t *vars, char *name, char *value)
{
	char *env_var, *curr_val;

	size_t name_len = _strlen(name);
	size_t value_len = _strlen(value);

	if (!(name) || (name_len == 0) || (_strchr(name, '=')))
	{
		return (-1);
	}
	curr_val = _getenv(vars, name);
	env_var = malloc(name_len + value_len + 2);
	_memcpy(env_var, name, name_len);
	env_var[name_len] = '=';
	_memcpy(env_var + name_len + 1, value, value_len);
	env_var[name_len + value_len + 1] = '\0';

	if (curr_val && (_strcmp(curr_val, value) != 0))
	{
		curr_val = curr_val - name_len - 1;
		/*curr_val = _strdup(env_var);*/
		_memcpy(curr_val, env_var, name_len + value_len + 2);
		free(env_var);
	}
	else if (!curr_val)
	{
		if (_putenv(env_var, vars) != 0)
		{
			free(env_var);
			return (-1);
		}
	}
	else
	{
		free(env_var);
	}

	return (0);
}
/**
 * _putenv - adds new element to the environment
 * @env_var: the variable to be added
 * @vars: global variables struct
 * Return: 0 on success, -1 on error.
 */
int _putenv(char *env_var, var_t *vars)
{
	size_t env_len, idx;
	char **new_env;

	for (env_len = 0; vars->env[env_len]; env_len++)
	{
		;
	}
	new_env = malloc((env_len + 2) * sizeof(char *));
	if (!(new_env))
	{
		return (-1);
	}

	/*_memcpy(new_env, vars->env, env_len * sizeof (char *));*/

	for (idx = 0; idx < env_len; idx++)
	{
		new_env[idx] = vars->env[idx];
	}
	new_env[env_len] = env_var;
	new_env[env_len + 1] = NULL;
	free(vars->env);

	vars->env = new_env;

	return (0);
}
/**
 * _unsetenv - deletes environment variable
 * @vars: struct containing variables
 * @name: env var
 * Return: 0 on success, -1 on error.
 */
int _unsetenv(var_t *vars, char *name)
{
	char *curr_val;
	size_t idx = 0;

	curr_val = _getenv(vars, name);
	if (curr_val)
	{
		curr_val = curr_val - (_strlen(name)) - 1;

		while (vars->env[idx] != curr_val)
		{
			idx++;
		}
		free(vars->env[idx]);
		for (; vars->env[idx]; idx++)
		{
			vars->env[idx] = vars->env[idx + 1];
		}
	}

	return (0);
}
