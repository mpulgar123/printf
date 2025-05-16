/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:42:09 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/05/16 19:53:14 by mpulgar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_printf(char const *format, ...)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while(format[i])
	{
		count += write(1, &format[i], 1);	
		i++;
	}
	
	return(count);
}

int main(void)
{
	char const format[] = "hola mundo %c soy  yo %i";
	ft_printf("gabriel esta rojo");
	return(0);
}