#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char **split_string(char *str, int *num_words, char *delim)
{
	char *token;
	int i = 0;
	int num_tokens = 0;
	int capacity = 10;
	char **words;

	words = malloc(sizeof(char *) * capacity);
	if (str == NULL || num_words == NULL || words == NULL || delim == NULL)
		return (NULL);

	token = my_strtok(str, delim);
	while (token != NULL)
	{
		if (i == capacity)
		{
			capacity *= 2;
			words = realloc(words, sizeof(char *) * capacity);
			if (words == NULL)
				return (NULL);
		}

		words[i] = strdup(token);
		if (words[i] == NULL)
			return (NULL);

		i++;
		num_tokens++;

		if (strcmp(delim, "#") != 0)
			token = my_strtok(NULL, delim);
	}

	*num_words = num_tokens;
	return (words);
}

char **handle_separator(char *input)
{
	int commands_len = 0;
	char **commands;
	char *semicolon, *spaces, *comments, *newline;

	if (input == NULL || input[0] == '\0')
		return (NULL);

	semicolon = strpbrk(strdup(input), ";");
	spaces = strpbrk(strdup(input), " ");
	comments = strpbrk(strdup(input), "#");
	newline = strpbrk(strdup(input), "\n");

	if (comments != NULL)
	{
		commands = split_string(input, &commands_len, "#");
	}
	else if (semicolon != NULL)
	{
		commands = split_string(input, &commands_len, ";");
	}
	else if (spaces != NULL)
	{
		commands = split_string(input, &commands_len, " ");
	}
	else if (newline)
	{
		commands = split_string(input, &commands_len, "\n");
	}

	return (commands);
}
/*
int handle_logical_operators(char *input)
{
	int commands_len = 0;
	char **commands;
	char *copy;
	char **result;
	int i;

	if (input == NULL || input[0] == '\0')
		return (NULL);

	copy = strdup(input);
	if (copy == NULL || or == NULL)
	{
		perror("strdup");
		free(copy);
		return (NULL);
	}

	if (strcmp(copy, "&&") == 0)
	{
		commands = split_string(input, &commands_len, "&&");
		if (commands == NULL)
		{
			perror("split_string");
			free(copy);
			return (NULL);
		}

		for (i = 0; i < commands_len - 1; i++)
		{
			result = exec(commands[i]);

			if (result != NULL)
			{
				exec(commands[i + 1]);

				free(result);
			}

			free(commands[i]);
		}

		free(commands[i]);
		free(commands);
	}
	else if (strcmp(copy, "||") == 0)
	{
		commands = split_string(input, &commands_len, "||");
		if (commands == NULL)
		{
			perror("split_string");
			free(copy);
			free(or);
			return (NULL);
		}

		for (i = 0; i < commands_len - 1; i++)
		{
			result = exec(commands[i]);
			if (result == NULL)
			{
				exec(commands[i + 1]);
				free(result);
			}

			free(commands[i]);
		}

		free(commands[i]);
		free(commands);
	}

	free(copy);
	return (0);
}

int main()
{
	char *command_line = NULL;
	size_t len = 0;
	char **commands;

	my_getline(&command_line, &len, stdin);

	commands = handle_separator(command_line);

	for (int i = 0; commands[i] != NULL; i++)
	{
		printf("%s\n", commands[i]);
	}

	free(commands);
	free(command_line);
	return 0;
}*/
