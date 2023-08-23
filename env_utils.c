#include "main.h"

int _chdir(var_t *vars, char *new_pwd)
{
	char *new_oldpwd = _getenv(vars, "PWD");
	char *emsg, *cd_msg = "can't cd to ";

	if (chdir(new_pwd) == -1)
	{
		emsg = malloc((strlen(cd_msg) + strlen(new_pwd)) * sizeof(char *));
		memcpy(emsg, cd_msg, strlen(cd_msg));
		memcpy(emsg + strlen(cd_msg), new_pwd, strlen(new_pwd));
		print_error(vars, emsg);
		_errputs("\n");
		free(emsg);
		return (-1);
	}
	_setenv(vars, "OLDPWD", new_oldpwd);
	_setenv(vars, "PWD", new_pwd);
	return (0);
}
