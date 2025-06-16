/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:21:36 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/06/16 13:49:12 by mpulgar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	cases(char **format)
{
	va_list	args;
	int count;
	
	count = 0;
	{
		i++;
		if (i == 'c')
			count = printchar(va_arg(args, int)) + count;
		if (i == 's')
			count = printstr(va_arg(args, char *)) + count;
		if (i == 'p')
			count = printptr(va_arg(args, void *)) + count;
		if (i == 'd' || i == 'i')
			count = print10(va_arg(args, int)) + count;
		if (i == '%')
			count = write(1, "%", 1) + count;
		if (i == 'x')
			count += printhex((unsigned long)va_arg(args, unsigned int), 'x');
		if (i == 'X')
			count += printhex((unsigned long)va_arg(args, unsigned int), 'X');
		if (i == 'u')
			count += printunsigned(va_arg(args, unsigned int));
	}
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			// if (format[i] == 'c')
				// count = printchar(va_arg(args, int)) + count;
			// if (format[i] == 's')
				// count = printstr(va_arg(args, char *)) + count;
			// if (format[i] == 'p')
				// count = printptr(va_arg(args, void *)) + count;
			// if (format[i] == 'd' || format[i] == 'i')
				// count = print10(va_arg(args, int)) + count;
			// if (format[i] == '%')
				// count = write(1, "%", 1) + count;
			// if (format[i] == 'x')
				// count += printhex((unsigned long)va_arg(args, unsigned int),
						// 'x');
			// if (format[i] == 'X')
				// count += printhex((unsigned long)va_arg(args, unsigned int),
						// 'X');
			// if (format[i] == 'u')
				// count += printunsigned(va_arg(args, unsigned int));
		}
		else
			count = write(1, &format[i], 1) + count;
		i++;
	}
	va_end(args);
	return (count);
}
// int	main(void)
// {
// int	a = 'm';
// ft_printf("hola %c", a);
// }
// write(1, '%', 1);
// count = 1 + count;