/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfapuntes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:42:09 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/05/29 17:48:24 by mpulgar-         ###   ########.fr       */
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
				count = putchar(va_arg(vargs,char)) + count; // en va ar esta la letra que vas a escribir
			//if (format[i] == 'i' || format[i] == 'd') así con todas
			
		}// acumulador_ acumula un valor  y lo va guardadnod en diferentes lonitudes
		
		count += write(1, &format[i], 1);	
		i++;
	}
	
	va_end(vargs); //ya no voy a usar estos cajones. limpia al final el que?? las cajotas?
	return(count);
}

int printchar(char c)
{
	return(write(1, &c, 1))// pones el write en eñ return porque deveuleve sta funicon la ccantidad de cosas qie mprime y es 1. 
}
%p El puntero void * dado como argumento se imprime en formato hexadecimal. // el void no e sporque ea puntero a  void sino porque ese void lo uedes castear a lo que ssea

//va_arg(vargs, char) //de los argumentos, el que de la pila tenga este tipo de dato lo obtiene

int printptr( void *ptr)
{
	int count;

	count = 0; // contar cuanto haz impreso COMO TODO EN EL PRINTF
	if(ptr == NULL)
		return(write(1, "(nil)", 5));
	count = write(1, "0x", 2);
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

 