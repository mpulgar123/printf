


#include <unistd.h>
#include "ft_printf.h"

int printchar(char c)
{
	return(write(1, &c, 1));
}
int print10(int i)
{
	char c;
	int count;
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}

	if (i >= '0' && i <= '9')
	{
		c = i + '0';
		write(1, &c, 1);
	}

	if (i >= 10)
	{
		print10(i / 10);
		c = (i % 10) + '0';
		write(1, &c, 1);
	}
	return(count);
}
int printstr(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	return(i - 1);
}
int printptr(void *ptr)
{
	int count;

	count = 0;
	if(ptr == NULL)
		return(write(1, "(nil)", 5));
	count = write(1, "0x", 2) + count;
	count = printhex((unsigned long) ptr) + count;
	return(count);
}
int printhex(unsigned long i)
{
	char c;
	int count;
	char	*base; // un array con los caracteres que uede iprimmir

	count = 0;
	base = "0123456789abcdef"; 
	if (i >= 10)
		count = printhex(i / 16) + count;
	c = base[i % 16]; // los [] representa la poscion de base que vas a printear
	count = write(1, &c, 1) + count;
	return(count);	
}





// int main(void)
// {
	// int i = 3;
	// print10(i);
	// return(0);
// }