
#Primero defino el nombre del programa
#(NAME tambien lo puedo llamar TARGET)

NAME = libft.a

INCLUDE = libft.h
#Aquí debo especificar los archivos .c que quiero compilar
SRC = ft_isalnum.c  ft_isascii.c  ft_isprint.c \


#SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c

#Aquí voy a convertir cada archivo .c en su equivalente .o
#por ejemplo, ft_bzero.c será ft_bzero.o.
OBJ = $(SRC:.c=.o)
#OBJ_BONUS = $(SRC_BONUS:.c=.o)

#Aquí defino el compilador (para C es cc)
#CC = cc
CC = cc

#Defino las banderas (flags) del compilador
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror

#Regla para generar una biblioteca estática. el .a que es el reuslltado de todo lloq eu hhaes en el makefil. rodo llo asocias ahi. 
all: $(NAME) CUNDO AHAGA E ALL SE HARA TODO LO ASOOCIADO ALL NAME. 

#Aqui creo que mi libreria (.a)
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

#bonus: $(OBJ) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

#Lo que dice es: Para crear $(NAME), es decir, libft.a, necesito los
#archivos .o que están en $(OBJ). Lo mismo para bonus.

#rcs: Son las banderas que se pasan al comando ar
#r: Reemplaza o agrega archivos a la biblioteca estática.
#c: Crea la biblioteca si no existe.
#s: Crea un índice (o tabla de símbolos) dentro de la biblioteca estática,
#lo que mejora el rendimiento al enlazar la biblioteca en programas más grandes.

#Esto es una regla génerica para compilar de .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

#Esto dice --> $(CC) : El compilador (por defecto es cc)
# $(CFLAGS): banderas de compilación (-Wall -Wextra -Werror)
# -c : Compila sin enlazar (genera .o, no ejecutables)
# $< : El archivo fuente .c (ej: ft_bzero.c)
# -o $@ : Dice que la salida debe llamarse como el archivo objetivo (ej: ft_bzero.o)

#Aquí borra los archivos .o,
# $(OBJ_BONUS)
clean:
	rm -f $(OBJ) 

#Esta regla es para borrar los archivos .o y .a (libft)
fclean: clean
	rm -f $(NAME)

#Esta regla es para limpiar todo y volver a compilar desde cero
re: fclean all

.PHONY: all clean fclean