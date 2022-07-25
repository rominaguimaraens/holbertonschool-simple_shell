#include "main.h"

void read_cmd(char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0, j;
	char *array[100], *pch;

	for (;;)
	{
		int c = fgetc(stdin);

		line[count++] = (char) c;

		if (c == '\n')
		{
			break;
		}
	}
	if (count == 1)
	{
		return;
	}
	pch = strtok(line, "\n");

	while (pch != NULL)
	{
		array[i++] = _strdup(pch);
		pch = strtok(NULL, "\n");
	}
	_strcpy(cmd, array[0]);

	for (j = 0; j < i; j++);
	{
		par[j] = array[j];
	}

	par[i] = NULL;
}
