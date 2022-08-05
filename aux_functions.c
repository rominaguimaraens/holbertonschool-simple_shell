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
char *_getenv(char *name)
{
	int i = 0;
	char *duplicate, *token;

	for (; environ; i++)
	{
		duplicate = _strdup(environ[i]);

		token = strtok(duplicate, "=");

		if (_strcmp(duplicate, name) == 0)
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

char **execute(char *buffer)
{
	char **str = NULL;
	char *ptr = _strdup(buffer), *token = NULL, *tok = NULL;
	int i = 0, args = 0;

	args = repeat(buffer, ' ') + 2;
	str = malloc(args * sizeof(char *));
	token = strtok(ptr, " ");
	for (i = 0; token; i++)
	{
		str[i] = _strdup(token);
		token = strtok(NULL, " ");
	}
	str[i] = NULL;
	if (repeat(str[0], '/') == 0)
	{
		tok = _strdup(str[0]);
		free(str[0]);
		str[0] = _which(tok);
		if (str[0] == NULL)
		{
			free(str[0]);
			str[0] = "none";
			free(ptr), free(tok);
			return (str);
		}
	}
	free(tok), free(ptr);
	return (str);
}
void freeing(char **var)
{
	int i = 0;

	for (; var[i]; i++)
		free(var[i]);
	free(var[i]), free(var);
}
