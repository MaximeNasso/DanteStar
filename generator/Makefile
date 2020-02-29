##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## main Makefile
##

NAME    =       generator

SOURCE  =	src/main.c	\
		src/generator_perfect.c	\
		src/map_gestion.c	\
		src/dig_func.c	\
		src/backtrack.c	\
		src/linked_list.c	\
		src/imperfect_maze.c	\
		src/checks.c	\

OBJ     =       $(SOURCE:.c=.o)

CFLAGS  =       -L./lib -lmy -I ./include

all :       	$(NAME)

$(NAME) :       $(OBJ)
		@(cd lib/my && $(MAKE))
		gcc -o $(NAME) $(SOURCE) $(CFLAGS)

clean   :
		rm -f $(OBJ)

fclean  :       clean
		rm -f $(NAME)
		rm -f ../tournament/$(NAME)
		rm lib/libmy.a

re :	fclean all
