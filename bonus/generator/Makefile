##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## main Makefile
##

NAME    =       generator

SOURCE  =       src/main.c  \
                src/generator_perfect.c \
                src/map_gestion.c   \
                src/dig_func.c  \
                src/backtrack.c \
                src/linked_list.c   \
                src/imperfect_maze.c    \
                src/checks.c    \
                src/graph/graphical_maze_sdl.c    \
                src/graph/graph.c \
                src/graph/csfml_maze.c  \

OBJ     =       $(SOURCE:.c=.o)

CFLAGS  =       -L./lib \
                -lmy \
                -I ./include \
                -l SDL \
                -l csfml-graphics  \
                -l csfml-window \
                -l csfml-system \

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
