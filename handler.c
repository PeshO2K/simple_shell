#include "main.h"
/**
 * _errputs - prints error to STDERR
 * @str: error message
 *
 * Return: pointer to the converted string
 */
void _errputs(char *str)
{
	ssize_t len, size;

	len = _strlen(str);
	size = write(STDERR_FILENO, str, len);
	if (len != size)
	{
		perror("Fatal Error");
		exit(1);
	}
}
/**
 * print_error - prints an error message
 * @vars: the parameter & return var_t struct
 * @emsg: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(var_t *vars, char *emsg)
{
	_errputs(vars->myname/*_getenv("_")*/);
	_errputs(": ");
	print_unsigned_int(vars->line_count);
	_errputs(": ");
	_errputs(vars->args[0]);
	_errputs(": ");
	if (!emsg)
	{
		perror("");
	}
	else
	{
		_errputs(emsg);
	}
}

/**
 * _uitoa - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 2));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	_puts(numstr);
	return (numstr);
}
/**
 * print_unsigned_int - prints unsigned int
 * @n: unsigned int to convert
 * Return: nothing
 */
void print_unsigned_int(unsigned int n)
{
	char buffer[10];
	int i = 0;

	if (n == 0)
	{
		write(2, "0", 1);
		return;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
	{
		write(2, &buffer[i], 1);
	}
}
