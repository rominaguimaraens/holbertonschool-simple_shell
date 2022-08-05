#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;
void freeing(char **var);
char **execute(char *buffer);
int repeat(char *str, char delim);
char *_getenv(const char *name);
char *_which(char *filename, ...);
char *_str_concat(char *s1, char *s2);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void prints(char **stru);
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
