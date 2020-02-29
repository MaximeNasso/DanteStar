/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** TODO: add description
*/

#include "generator.h"

void backtrack(data_t *data)
{
    node_t *tmp = data->pos->last;

    if (data->pos->last->prev != NULL) {
        data->pos->last = data->pos->last->prev;
        data->pos->last->next = NULL;
        data->r = data->pos->last->y;
        data->c = data->pos->last->x;
        free(tmp);
        data->pos_blocked[UP] = 0;
        data->pos_blocked[DOWN] = 0;
        data->pos_blocked[LEFT] = 0;
        data->pos_blocked[RIGHT] = 0;
    } else {
        free(tmp);
        free(data->pos);
        data->pos = NULL;
    }
}

void free_struct(data_t *data)
{
    free_tab(data->map);
    free_list(data->pos);
    free(data->pos_blocked);
    free(data);
}