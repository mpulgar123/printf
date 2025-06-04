


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
	count = printhex((unsigned long) ptr, 'p') + count;
	return(count);
}
int printhex(unsigned long i, char b)
{
	char c;
	int count;
	char	*base; 

	count = 0; 
	if (b == 'X')
		base = "0123456789ABCDEF"; 
	else
		base = "0123456789abcdef";	
	if (i >= 16)
		count = printhex(i / 16, b) + count;
	c = base[i % 16];
	count = write(1, &c, 1) + count;
	return(count);
}
int printdec(int num)
{
	int i;
	int count;
	char c;

	count = 0;
	i = 0;
	
	if (num[i] == ',')

	if (num >= 10)
	printdec(num / 10);
	c = write(1, &c, 1);

	
}

// int printhexminman(int i)
// {
// 
// }

// int printper(int c)
// {
	// int count;
	// count = write(1, &c, 1); //pasar a char con + 0 ?
	// return (count);
// }




// int main(void)
// {
	// int i = 3;
	// print10(i);
	// return(0);
// }