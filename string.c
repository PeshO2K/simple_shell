#include "main.h"
/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else if (num > 0)
			break;
	} while (*s++);
	return (num * sign);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line
 * @str: string to be printed
 * Return: void
 */
void _puts(char *str)
{
	if (!str)
	{
		return;
	}
	while (*str != '\0')
	{
		_putchar (*str);
		str++;
	}
}
/**
 * _strlen - return length of string
 * @s: string pointer
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	size_t counter = 0;

	if (s)
	{
		while (*s != '\0')
		{
			counter++;
			s++;
		}
	}
	return (counter);
}

/**
 * _strcpy - Copies a string pointed to by @src, including the
 * terminating null byte, to a buffer pointed to by @dest.
 * @dest: A buffer to copy the string to.
 * @src: A source string to cpoy.
 *
 * Return: A pointer to the destination string @dest.
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	if ((dest != src) && (src))
	{
		for (i = 0; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
	}
	return (dest);
}
