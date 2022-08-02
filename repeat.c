#include "main.h"

int repeat(char *str)
{
	int i, len = strlen(str), count = 0;

	for (i = 0; i<= len; i++)
	{
		if (str[i] == ':')
			count++;
	}
	return (count);
}
