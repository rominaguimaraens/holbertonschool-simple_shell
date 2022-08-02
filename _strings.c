#include "main.h"

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
* _strcpy - copies string to dest
* @dest: destination
* @src: source
* Return: returns dest
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strcmp - compare strings
 * @s1: first string
 * @s2: second string
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i])
	{
		return (s2[i]);
	}
	return (0);
}

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
