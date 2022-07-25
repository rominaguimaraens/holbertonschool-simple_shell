#include "main.h"
#include <unistd.h>

void prompt(void)
{
	static int first_time = 1;

	if (first_time)
	{
		const char* clear_screen = "\e[1;1H\e[2J";
		write(STDOUT_FILENO, clear_screen, 12);
		first_time = 0;
	}
	_printf("$");
}
