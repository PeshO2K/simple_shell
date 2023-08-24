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
		emsg = malloc((strlen(cd_msg) + _strlen(new_pwd)) * sizeof(char));
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
 * comment_handler - replaces '#' with '\0'
 * @buff: string buffer address
 * Return: Nothing
 */
void comment_handler(char *buff)
{
	size_t i = 0;

	for (; buff[i] != '\0'; i++)
	{
		
		if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
	}
}
