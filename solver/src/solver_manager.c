/*
** EPITECH PROJECT, 2019
** dante
** File description:
** solver_manager.c
*/

#include "my.h"

int solver_manager(char **av, data_t *data)
{
    get_data(data, av);
    data->i_maze = create_i_maze(data);
    check_start_end(data);
    solver_algo(data);
    return (0);
}

void backtrack(data_t *data, list_t *list)
{
    intersection_t *tmp = list->tail;

    if (list->tail->prev != NULL) {
        data->i_maze[list->tail->y][list->tail->x] = 2;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        data->y = list->tail->y;
        data->x = list->tail->x;
        free(tmp);
    } else {
        printf("no solution found");
        free_manager(data);
        exit (0);
    }
}

void move_algo(data_t *data, int y, int x, list_t *list)
{
    data->y = y;
    data->x = x;
    list = add_node(list, data->y, data->x);
    data->i_maze[data->y][data->x] = 3;
}

int solver_algo(data_t *data)
{
    list_t *list = NULL;

    list = add_node(list, 0, 0);
    data->i_maze[0][0] = 3;
    solve_loop(data, list);
    create_final_maze(data, list);
    free_manager(data);
    free_list(list);
}

void solve_loop(data_t *data, list_t *list)
{
    while (42) {
        if (data->y == data->y_max - 1 && data->x == data->x_max - 1)
            break;
        if (check_coord(data, data->y, data->x+1) == 0) {
            move_algo(data, data->y, ++data->x, list);
            continue;
        }
        if (check_coord(data, data->y, data->x-1) == 0) {
            move_algo(data, data->y, --data->x, list);
            continue;
        }
        if (check_coord(data, data->y-1, data->x) == 0) {
            move_algo(data, --data->y, data->x, list);
            continue;
        }
        if (check_coord(data, data->y+1, data->x) == 0) {
            move_algo(data, ++data->y, data->x, list);
            continue;
        }
        backtrack(data, list);
    }
}