/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** TODO: add description
*/

#include "generator.h"

void dig(data_t *data)
{
    switch (data->rand_value) {
        case UP:
            --data->r;
            break;
        case DOWN:
            ++data->r;
            break;
        case LEFT:
            --data->c;
            break;
        case RIGHT:
            ++data->c;
            break;
    }
    if (data->blocked != 4)
        data->pos = add_node(data->c, data->r, data->pos);
    data->pos_blocked[UP] = 0;
    data->pos_blocked[DOWN] = 0;
    data->pos_blocked[LEFT] = 0;
    data->pos_blocked[RIGHT] = 0;
    data->map[data->r][data->c] = '*';
}

void create_end(data_t *data)
{
    if (data->r + 3 == data->y && data->c + 1 == data->x) {
        data->map[data->r + 1][data->c] = '*';
        data->map[data->r + 2][data->c] = '*';
        data->end = 1;
    }
    if (data->r + 2 == data->y && data->c + 2 == data->x) {
        data->map[data->r + 1][data->c + 1] = '*';
        data->map[data->r][data->c + 1] = '*';
        data->end = 2;
    }
    if (data->r + 1 == data->y && data->c + 3 == data->x) {
        data->map[data->r][data->c + 1] = '*';
        data->map[data->r][data->c + 2] = '*';
        data->end = 3;
    }
}