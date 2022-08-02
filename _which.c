#include "main.h"
#include <string.h>
/**
 *
 */
char *_which(char *filename, ...)
{
	int i, args = 0;
	struct stat st;
	char *token = NULL, *duplicate = NULL, *aux = NULL, *aux2 = NULL;
	char **saved;

	duplicate = _getenv("PATH");
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
