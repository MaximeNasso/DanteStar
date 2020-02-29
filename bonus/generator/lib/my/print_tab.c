/*
** EPITECH PROJECT, 2019
** print_tab
** File description:
** print_tab.c
*/

#include "my.h"

int print_tab(char **tab)
{
    for (int y = 0; tab[y]; y++) {
        write(1, tab[y], my_strlen(tab[y]));
        if (tab[y + 1])
            write(1, "\n", 1);
    }
    return (0);
}
