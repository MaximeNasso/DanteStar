##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## lib Makefile
##

NAME	=	libmy.a

SOURCE	=	$(shell find -type f -name '.c')

OBJ	=	$(SOURCE:.c=.o)

CFLAGS	=	-I../../include

all	:	$(NAME)

$(NAME)	:
		@(gcc -c *.c $(CFLAGS))
		@(ar rc $(NAME) *.o)
		rm *.o
		@(mv $(NAME) ..)

clean	:	all
		find -type f -name '*~' -delete
		find -type f -name '*#' -delete

fclean	:	clean
		rm ../$(NAME)
