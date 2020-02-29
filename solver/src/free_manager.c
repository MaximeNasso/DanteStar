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
    free_int_tab(data->i_maze, data);
    free(data);

    return (0);
}

int free_int_tab(int **tab, data_t *data)
{
    for (int i = 0; i < data->y_max; i++)
        free(tab[i]);
    free(tab);

    return (0);
}

void free_list(list_t *list)
{
    intersection_t *node = list->head;
    intersection_t *tmp = NULL;

    if (node == NULL)
        exit (0);
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    free(list);
}