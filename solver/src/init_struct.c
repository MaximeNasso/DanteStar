/*
** EPITECH PROJECT, 2019
** dante
** File description:
** init_struct.c (solver)
*/

#include "my.h"

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));

    data->x = 0;
    data->y = 0;
    data->x_max = 0;
    data->y_max = 0;
    data->maze = NULL;
    data->i_maze = NULL;

    return (data);
}

list_t *add_node(list_t *list, int y, int x)
{
    intersection_t *new = malloc(sizeof(intersection_t));

    new->next = NULL;
    new->prev = NULL;
    new->x = x;
    new->y = y;
    if (list == NULL) {
        list = malloc(sizeof(list_t));
        list->head = new;
        list->tail = new;
    } else {
        list->tail->next = new;
        new->prev = list->tail;
        list->tail = new;
    }
    return (list);
}