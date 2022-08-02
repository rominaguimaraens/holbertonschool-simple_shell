#include "main.h"
/**
 *
 */
int main(int argc, char **argv)
{
        size_t bufsize = 0;
        char *buffer = NULL, *buffer2 = NULL, *location[] = {"", "/usr", NULL}, *token = NULL;
        size_t character;
	int pid = 0, status;

	while (buffer2 != "no")
	{
		printf("$ ");
		character = getline(&buffer, &bufsize, stdin);
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
