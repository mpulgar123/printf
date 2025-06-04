#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(char const *format, ...);
int printchar(char c);
int print10(int i);
int printstr(char *c);
int printptr(void *ptr);
int printhex(unsigned long i, char b);


//int printper(char c);

#endif