/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:21:36 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/05/29 18:12:43 by mpulgar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf(char *format, ...)
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
			if (format[i] == 'c')
				count = printchar(va_arg(args, int)) + count;
			if (format[i] == 's')
				count = printstr(va_arg(args, char *)) + count;
			if (format[i] == 'p')
				count = printptr(va_arg(args, void*)) + count;
			if (format[i] == 'd' || format[i] == 'i')
				count = print10(va_arg(args, int)) + count;
		}
		else
			write(1, &format[i], 1);
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