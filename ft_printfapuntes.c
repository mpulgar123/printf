/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:42:09 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/05/28 19:12:03 by mpulgar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_printf(char const *format, ...)
{
	va_list vargs; //variable para manejar los argumentos variables
	int i; //recorrer los formatos
	int count; // el printf devuelve un int de la cantidad de cajas que imprime

	i = 0;
	count = 0;
	va_start (vargs, format); //inicializas el manejo de argumentos a partir de lo anteior a los ... so a paprtir de format
	
	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count = putchar(va_arg(vargs,int)) + count;
			//if (format[i] == 'i' || format[i] == 'd') así con todas
			
		}
		
		count += write(1, &format[i], 1);	
		i++;
	}
	
	va_end(vargs); //ya no voy a usar estos cajones. limpia al final el que?? las cajotas?
	return(count);
}

//va_arg(vargs, char) //de los argumentos, el que de la pila tenga este tipo de dato lo obtiene


// int ft_printf(char const *format, ...)
// {
	// int i;
	// int count;
	// 
	// i = 0;
	// count = 0;
	// while(format[i])
	// {
		// count += write(1, &format[i], 1);	
		// i++;
	// }
	// 
	// return(count);
// }

int main(void)
{
	char const format[] = "hola mundo %c soy  yo %i";
	ft_printf("gabriel esta rojo");
	return(0);
}

 