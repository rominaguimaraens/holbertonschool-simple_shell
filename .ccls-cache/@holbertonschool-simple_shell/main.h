#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _printf(const char *format, ...);
int print_number(va_list list);
int print_char(va_list list);
int print_string(va_list list);
int _putchar(char c);

/**
 * struct prf - posible character
 * @letter: letter to check
 * @f: pointer to list
 */
typedef struct prf
{
	char letter;
	int (*f)(va_list);
} print;
#endif
