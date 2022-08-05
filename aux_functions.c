#include "main.h"
#include <string.h>
/**
 * _which - shows the full path of command
 * @filename: command
 * Return: path of command
 */
char *_which(char *filename, ...)
{
	int i, args = 0;
	struct stat st;
	char *token = NULL, *duplicate = NULL, *aux = NULL, *aux2 = NULL;
	char **saved;

	duplicate = _getenv("PATH");
	args = repeat(duplicate, ':') + 2;
	saved = malloc(args * sizeof(char *));
	if (saved == NULL)
		return ("error");
	token = strtok(duplicate, ":");
	for (i = 0; token; i++)
	{
		saved[i] = _strdup(token);
		token = strtok(NULL, ":");
	}
	saved[i] = NULL;
	for (i = 0; i < 7; i++)
	{
		aux = _str_concat(saved[i], "/");
		aux2 = _str_concat(aux, filename);
		if (stat(aux2, &st) == 0)
			break;
		free(aux);
		free(aux2);
	}
	for (i = 0; saved[i]; i++)
		free(saved[i]);
	return (aux2);
	}

/*
 * _getenv - gets environment variable
 * @name: name of the variable
 * Return: pointer to the value
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *duplicate, *token;

	for (; environ; i++)
	{
		duplicate = _strdup(environ[i]);

		token = strtok(duplicate, "=");

		if (strcmp(duplicate, name) == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
		else
			continue;
	}
	return (0);
}

/*
 * repeat - counts delimiter characters
 * @str: string to check
 * @delim: delimiter character
 * Return: count
 */
int repeat(char *str, char delim)
{
	int i, len = strlen(str), count = 0;

	for (i = 0; i <= len; i++)
	{
		if (str[i] == delim)
			count++;
	}
	return (count);
}
