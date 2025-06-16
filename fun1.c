/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:07:11 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/06/16 13:25:24 by mpulgar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	printchar(char c)
{
	return (write(1, &c, 1));
}
int	print10(int i)
{
	char	c;
	int		count;

	count = 0;
	if (i == -2147483648)
		write(1, "-2147483648", 10);
	if (i < 0)
	{
		count += write(1, "-", 1);
		i = -i;
	}
	if (i >= 0 && i <= 9)
	{
		c = i + '0';
		count += write(1, &c, 1);
	}
	if (i >= 10)
	{
		count += print10(i / 10);
		c = (i % 10) + '0';
		count += write(1, &c, 1);
	}
	return (count);
}
int	printstr(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (write(1, "(null)", 6));
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}
int	printptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2) + count;
	count = printhex((unsigned long)ptr, 'p') + count;
	return (count);
}

// if (num[i] == ',')
//
// if (num >= 10)
// printdec(num / 10);
// c = write(1, &c, 1);
// eliminar la coma
// }
//
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