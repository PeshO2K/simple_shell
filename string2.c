#include "main.h"
/**
 * _strncpy - Copies at most an inputted number
 *            of bytes from string src into dest.
 * @dest: The buffer storing the string copy.
 * @src: The source string.
 * @n: The maximum number of bytes to copied from src.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, len = _strlen(src);

	for (i; src[i] && i < n; i++)
	{
		dest[i] = src[i];
	}

	for (i = len; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strncat - Concatenates two strings using at most
 *            an inputted number of bytes from src.
 * @dest: The string to be appended upon.
 * @src: The string to be appended to dest.
 * @n: The number of bytes from src to be appended to dest.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, len = _strlen(dest);

	for (i; src[i] && i < n; i++)
	{
		dest[len++] = src[i];
	}
	return (dest);
}

/**
 * _strcmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 *
 * Return: If str1 < str2, the negative difference
 *         If str1 == str2, 0.
 *         If str1 > str2, the positive difference
 */
int _strcmp(char *s1, char *s2)
{
	 while (*s1 && *s2 && *s1 == *s2)
	 {
		 s1++;
		 s2++;
	 }
	 return (*s1 - *s2);
}

/**
 * _strchr - return first occurrence of character
 * @c: character to be found
 * @s: character string
 * Return: NULL if not found otherwise pointer.
 */
char *_strchr(char *s, char c)
{
	while (*s >= '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}

/**
 * _strncmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 *
 * Return: If str1 < str2, the negative difference
 *         If str1 == str2, 0.
 *         If str1 > str2, the positive difference
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*s1 - *s2);
}
