#include "main.h"

/**
 * get_op_fp - finds character to replace
 * @y: character to check
 * va_list - list of cases
 * Return: returns null
 */

int (*get_op_fp(char y))(va_list)
{
	int z = 0;
	print atr[] = { {'c', print_char},
			{'s', print_string},
			{'d', print_number},
			{'i', print_number},
 			{'\0', NULL} };

	while (atr[z].letter != '\0')
	{
		if (y == atr[z].letter)
		{
			return (atr[z].f);
		}
		z++;
	}
	return (NULL);
}

/**
 * _printf - prints strings and different inputs
 * @format: string to print
 * Return: returns length of string
 */
int _printf(const char *format, ...)
{
/**	char *sep;*/
	int x, c = 0;
	va_list list;


	va_start(list, format);
	if (format == NULL)
		return (-1);
	for (x = 0; format != NULL && format[x] != '\0'; x++)
	{
		if (format[x] == '%' && format[x + 1] == '%')
		{
			_putchar('%');
			x++;
			c++;
		}
		else if (format[x] == '%' && format[x + 1] == '\0')
			return (-1);
		else if (format[x] == '%')
		{
			if (*(get_op_fp(format[x + 1])) == NULL)
			{
				_putchar(format[x]);
				_putchar(format[x + 1]);
				c += 2;
			}
			else
			{
				c += (*(get_op_fp(format[x + 1])))(list);
			}
			x++;
		}
		else
		{
			_putchar(format[x]);
			c++;
		}
	}
	va_end(list);
	return (c);
}
