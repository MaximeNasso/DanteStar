/*
** EPITECH PROJECT, 2019
** dante
** File description:
** tools_functions.c
*/

#include "my.h"

void print_int_tab(int y, int x, int **tab)
{
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++)
            printf("%d", tab[j][i]);
        printf("\n");
    }
}

int check_file(char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] != 'X' && str[i] != '\n' && str[i] != '*') {
            printf("no solution found");
            exit (0);
        }
    }
    return (0);
}