/*
** EPITECH PROJECT, 2019
** free_tab
** File description:
** free_tab.c
*/

#include "my.h"

int free_tab(char **tab)
{
    for (int y = 0; tab[y]; y++)
        free(tab[y]);
    free(tab);
}