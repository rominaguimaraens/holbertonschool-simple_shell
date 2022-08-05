#include "main.h"
/**
 * main - Entry point
 * Return: 0 (success)
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	size_t bufsize = 0;
	char *buffer = NULL, **location = NULL;
	char *token = NULL;
	int status = 0;

	while (1)
	{
		if (isatty(0) == 1)
		{
			printf("$ ");
		}
		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			exit(0);
		}
		token = strtok(buffer, "\n");

		if (_strcmp(token, "exit") == 0)
			break;
		if (!token)
		{
			free(buffer);
			return (0);
		}
		location = execute(token);

		if (fork() == 0)
		{
			if (execve(location[0], location, environ) == -1)
			{
				perror(argv[0]);
				return (0);
			}
		}
		else
		{
			wait(&status);
			bufsize = 0;
			buffer = NULL;

			free(token);
			freeing(location);
		}
	}
	return (0);
}
