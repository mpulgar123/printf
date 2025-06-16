/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:07:11 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/06/16 13:25:10 by mpulgar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(char const *format, ...);
int	printchar(char c);
int	print10(int i);
int	printstr(char *c);
int	printptr(void *ptr);
int	printhex(unsigned long i, char b);
int	printunsigned(unsigned int i);

// int printper(char c);

#endif