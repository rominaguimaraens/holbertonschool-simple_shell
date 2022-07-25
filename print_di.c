#include "main.h"

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
