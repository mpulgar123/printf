/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:07:11 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/06/05 17:48:32 by mpulgar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
int printunsigned(unsigned int i)
{
	int count;
	char c;
	count = 0;
	if (i >= 0 && i <= 9)
	{
		c = i + '0';
		count += write(1, &c, 1);
	}
	if (i >= 10)
	{
		count += printunsigned(i / 10);
		c = (i % 10) + '0';
		count += write(1, &c, 1);
	}
	return(count);
}