#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_number_xd(unsigned n);

/**
* print_number - print a number
* @n: is an input
*/

int print_number(va_list list)
{
		int n = va_arg(list, int);
		
		if (n < 0)
		{
			_putchar('-');
			return (print_number_xd(-n) + 1);
		}
		else
		{
			return (print_number_xd(n));
		}
}

/**
* print_number_xd - print a number
* @n: is an input
*/

int print_number_xd(unsigned int n)
{
	int c = 0;

	if (n / 10 != 0)
	{
		c = print_number_xd(n / 10);
	}
	return (_putchar((n % 10) + '0') + c);
}

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
