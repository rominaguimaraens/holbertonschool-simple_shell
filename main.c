#include "main.h"
/**
 *
 */
int main(void)
{
	size_t bufsize = 0;
	char *buffer = NULL, *buffer2 = NULL, *location[] = {"", "/usr", NULL};
	char *token = NULL;
	int pid = 0, status;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
		buffer2 = _strdup(buffer);
		token = strtok(buffer2, "\n");
		pid = fork();
		
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			location[0] = _which(token);
			if (execve(location[0], location, NULL) == -1)
				perror("Error: ");
		}
		wait(&status);
	}
	return (0);
}

/**
 * *_strdup - copies the string given as parameter
 * @str: string to duplicate
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[i] = str[i]) != '\0')
		i++;

	return (dup);
}

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

char *_str_concat(char *s1, char *s2)
{
	char *conc;
	int p1, p2 = 0, len;

	if (s1 != NULL && s2 == NULL)
		len = strlen(s1);
	if (s1 == NULL && s2 != NULL)
		len = strlen(s2);
	if (s1 != NULL && s2 != NULL)
		len = (strlen(s1) + strlen(s2));
	len += 1;
	conc = malloc(len);
	if (conc == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		for (p1 = 0; s1[p1]; p1++)
		{
			conc[p2] = s1[p1];
			p2++;
		}
	}
	if (s2 != NULL)
	{
		for (p1 = 0; s2[p1]; p1++)
		{
			conc[p2] = s2[p1];
			p2++;
		}
	}
	conc[p2] = '\0';
	return (conc);
}

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
