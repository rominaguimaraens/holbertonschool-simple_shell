#include "main.h"
/**
 * main - Entry point
 * Return: 0 (success)
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	size_t bufsize = 0;
	char *buffer = NULL, *buffer2 = NULL, *location[] = {"", "/usr", NULL};
	char *token = NULL;
	int pid = 0, status;

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
		buffer2 = _strdup(buffer);
		token = strtok(buffer2, "\n");
		pid = fork();

		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			location[0] = _which(token);
			if (execve(location[0], location, NULL) == -1)
				perror(argv[0]);
		}
		wait(&status);
		free(buffer2);
		buffer = NULL;

	}
	return (0);
}
