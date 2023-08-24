#include "main.h"
/**
 * _chdir - changes working directory
 * @vars: global variables struct
 * @new_pwd: new working directory
 * Return: 0 success, -1 on error
 */
int _chdir(var_t *vars, char *new_pwd)
{
	char *new_oldpwd = _getenv(vars, "PWD");
	char *emsg, *cd_msg = "can't cd to ";

	if (chdir(new_pwd) == -1)
	{
		emsg = malloc((strlen(cd_msg) + _strlen(new_pwd)) * sizeof(char *));
		_memcpy(emsg, cd_msg, _strlen(cd_msg));
		_memcpy(emsg + _strlen(cd_msg), new_pwd, _strlen(new_pwd));
		print_error(vars, emsg);
		_errputs("\n");
		free(emsg);
		return (-1);
	}
	_setenv(vars, "OLDPWD", new_oldpwd);
	_setenv(vars, "PWD", new_pwd);
	return (0);
}
/**
 * count_tokens - return number of tokens
 * @cmd: the command
 * @delim: the delimiters
 * Return: count
 */
int count_tokens(const char *cmd, const char *delim)
{
	int count = 0;
	char *str, *token;

	str = _strdup(cmd);
	for (;; str = NULL)
	{
		token = my_strtok(str, delim);
		if (token == NULL)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	free(str);
	return (count);
}
