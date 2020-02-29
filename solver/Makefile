##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## main Makefile
##

NAME    =       solver

SOURCE  =       src/main.c	\
		src/data_manager.c	\
		src/solver_manager.c	\
		src/init_struct.c	\
		src/tools_functions.c	\
		src/solver_manager_bis.c	 \
		src/free_manager.c

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
