##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## main Makefile
##

all :
		make -C generator
		make -C solver
		cp generator/generator tournament/
		cp solver/solver tournament/

clean   :
		make clean -C generator
		make clean -C solver

fclean  :       clean
		make fclean -C generator
		make fclean -C solver

re :	make re -C generator
	make re -C solver