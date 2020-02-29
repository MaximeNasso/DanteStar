/*
** EPITECH PROJECT, 2019
** dante
** File description:
** free_manager.c
*/

#include "my.h"

int free_manager(data_t *data)
{
    free_tab(data->maze);
    free(data);

    return (0);
}

int free_int_tab(int **tab, data_t *data)
{
    for (int i = 0; i <= data->y; i++)
        free(tab[i]);
    free(tab);

    return (0);
}