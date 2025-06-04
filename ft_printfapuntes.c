/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfapuntes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:42:09 by mpulgar-          #+#    #+#             */
/*   Updated: 2025/06/04 17:44:47 by mpulgar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_printf(char const *format, ...) //format es el puntero a un acadena dde caraceres que contiene el texto que quieeres imprimir
//printf("hola %s", nombre) es lo que esta en ""
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
		//es + 1 en count porque acumua la canntidad que imprime. no importa nada la primera vez porque es mas 0 , pero lluego llos vallore suman y es importante suma rlo que tenias con la cantdad que etsas mprimiendo
		
		count += write(1, &format[i], 1);	
		i++;
	}
	else
	count = write(1, &format[i], 1) + count; // tambine debo acumullar los carcateres que imprime que n son ninguno de estos que me piden
	
	va_end(vargs); //ya no voy a usar estos cajones. limpia al final el que?? las cajotas?
	return(count);
}

FUNCIONES POR SEPARADO

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
int printhex(unsigned long i) //asi asegurass que no tiene signo y es llong para que no t epreocupes por desboradamienot 
{
	char c; // ara imprimir numeor uno por uno
	int count;
	char	*base; //un array con los caracteres que puede iprimmir

	count = 0;
	base = "0123456789abcdef"; //puntero con los caracteres psibles emhexa decimal. ej: bas[10] : a.
	if (i >= 10) //Si el número es mayor o igual a 10 
		count = printhex(i / 16) + count;// (es decir, tiene más de un dígito en hexadecimal), haces una llamada recursiva a `printhex(i / 16)`
		// recursiva para imprimir los digitos de izuierda a derecha
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

 