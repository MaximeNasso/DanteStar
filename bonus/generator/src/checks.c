/*
** EPITECH PROJECT, 2019
** generator
** File description:
** TODO: add description
*/

#include "generator.h"

void check_down(data_t *data)
{
    if (data->r + 1 >= data->y) {
        data->pos_blocked[DOWN] = BLOCKED;
        ++data->blocked;
        return;
    }
    if (data->map[data->r + 1][data->c] == '*') {
        data->pos_blocked[DOWN] = BLOCKED;
        ++data->blocked;
        return;
    }
    if ((data->c + 1 < data->x && data->map[data->r + 1][data->c + 1] == '*')
        || (data->c - 1 >= 0 && data->map[data->r + 1][data->c - 1] == '*')) {
        data->pos_blocked[DOWN] = BLOCKED;
        ++data->blocked;
        return;
    }
    if (data->r + 2 < data->y && data->map[data->r + 2][data->c] == '*') {
        data->pos_blocked[DOWN] = BLOCKED;
        ++data->blocked;
        return;
    }
}

void check_right(data_t *data)
{
    if (data->c + 1 >= data->x) {
        data->pos_blocked[RIGHT] = BLOCKED;
        ++data->blocked;
        return;
    }
    if (data->map[data->r][data->c + 1] == '*') {
        data->pos_blocked[RIGHT] = BLOCKED;
        ++data->blocked;
        return;
    }
    if ((data->r + 1 < data->y && data->map[data->r + 1][data->c + 1] == '*')
        || (data->r - 1 >= 0 && data->map[data->r - 1][data->c + 1] == '*')) {
        data->pos_blocked[RIGHT] = BLOCKED;
        ++data->blocked;
        return;
    }
    if (data->c + 2 < data->x && data->map[data->r][data->c + 2] == '*') {
        data->pos_blocked[RIGHT] = BLOCKED;
        ++data->blocked;
        return;
    }
}

void check_left(data_t *data)
{
    if (data->c - 1 < 0) {
        data->pos_blocked[LEFT] = BLOCKED;
        ++data->blocked;
        return;
    }
    if (data->map[data->r][data->c - 1] == '*') {
        data->pos_blocked[LEFT] = BLOCKED;
        ++data->blocked;
        return;
    }
    if ((data->r + 1 < data->y && data->map[data->r + 1][data->c - 1] == '*')
        || (data->r - 1 >= 0 && data->map[data->r - 1][data->c - 1] == '*')) {
        data->pos_blocked[LEFT] = BLOCKED;
        ++data->blocked;
        return;
    }
    if (data->c - 2 >= 0 && data->map[data->r][data->c - 2] == '*') {
        data->pos_blocked[LEFT] = BLOCKED;
        ++data->blocked;
        return;
    }
}

void check_up(data_t *data)
{
    if (data->r - 1 < 0) {
        data->pos_blocked[UP] = BLOCKED;
        ++data->blocked;
        return;
    }
    if (data->map[data->r - 1][data->c] == '*') {
        data->pos_blocked[UP] = BLOCKED;
        ++data->blocked;
        return;
    }
    if ((data->c + 1 < data->x && data->map[data->r - 1][data->c + 1] == '*')
        || (data->c - 1 >= 0 && data->map[data->r - 1][data->c - 1] == '*')) {
        data->pos_blocked[UP] = BLOCKED;
        ++data->blocked;
        return;
    }
    if (data->r - 2 >= 0 && data->map[data->r - 2][data->c] == '*') {
        data->pos_blocked[UP] = BLOCKED;
        ++data->blocked;
        return;
    }
}