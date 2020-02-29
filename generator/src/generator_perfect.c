/*
** EPITECH PROJECT, 2019
** dante
** File description:
** generator.c
*/

#include "generator.h"

void find_rand(data_t *data)
{
    int rdm = rand() % 4;

    if (data->blocked == 3) {
        rdm = 0;
        while (data->pos_blocked[rdm] == BLOCKED) {
            ++rdm;
        }
        data->rand_value = rdm;
    } else {
        while (data->pos_blocked[rdm] == BLOCKED)
            rdm = rand() % 4;
        data->rand_value = rdm;
    }
}

void dig_maze(data_t *data)
{
    if (!data->end && ((data->r + 3 == data->y && data->c + 1 == data->x)
    || (data->r + 2 == data->y && data->c + 2 == data->x)
    || (data->r + 1 == data->y && data->c + 3 == data->x)))
        create_end(data);
    check_up(data);
    check_down(data);
    check_left(data);
    check_right(data);
    if (data->blocked == 4) {
        backtrack(data);
    } else {
        find_rand(data);
        dig(data);
        data->done = 1;
    }
    data->blocked = 0;
}

void init_data(data_t *data, char **to_print, int x, int y)
{
    data->pos = NULL;
    data->map = to_print;
    data->pos_blocked = malloc(sizeof(int) * 4);
    data->pos_blocked[UP] = BLOCKED;
    data->pos_blocked[DOWN] = 0;
    data->pos_blocked[LEFT] = BLOCKED;
    data->pos_blocked[RIGHT] = 0;
    data->r = 0;
    data->c = 0;
    data->x = x;
    data->y = y;
    data->rand_value = -1;
    data->done = 0;
    data->blocked = 0;
    data->pos = add_node(data->c, data->r, data->pos);
}

void create_perfect(char **av, int imp)
{
    data_t *data = malloc(sizeof(data_t));
    long x = 0;
    long y = 0;
    char **to_print = NULL;

    x = strtol(av[1], &av[1], 10);
    y = strtol(av[2], &av[2], 10);
    to_print = create_map(x, y);
    init_data(data, to_print, x, y);
    srand(time(0));
    data->imp = imp;
    while (42) {
        if (!data->pos->first->next && data->done == 1)
            break;
        dig_maze(data);
    }
    final_disp(data);
}