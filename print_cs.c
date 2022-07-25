#include "main.h"
/**
 * print_char - prints a character
 * @list: list of cases
 * Return: 1
 */
int print_char(va_list list)
{
	int c;

	c = va_arg(list, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @list: list of cases
 * Return: length of string
 */
int print_string(va_list list)
{
	char *p;
	int s;

	p = va_arg(list, char *);

	if (p == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	for (s = 0; p[s] != '\0'; s++)
		_putchar(p[s]);
	return (s);
}
