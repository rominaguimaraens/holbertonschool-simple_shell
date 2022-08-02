#include "main.h"

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
