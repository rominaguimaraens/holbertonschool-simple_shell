#include "main.h"
/**
* _strcat - concatenates two strings
* @dest: destination string
* @src: other string
* Return: returns dest
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j;

	while (dest[i])
  	{
		i++;
	}
	for (j = 0; src[j]; j++, i++)
	{
		dest[i] = src[j];
	}
	dest[i] = 0;
	return (dest);
}
