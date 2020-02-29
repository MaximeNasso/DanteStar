/*
** EPITECH PROJECT, 2019
** danter
** File description:
** solver_manager_bis.c
*/

#include "my.h"

void check_start_end(data_t *data)
{
    if (data->maze[0][0] == 'X'
    || data->maze[data->y_max-1][data->x_max-1] == 'X') {
            printf("no solution found");
            free_manager(data);
            exit(0);
        }
}

int check_coord(data_t *data, int y, int x)
{
    if (y >= 0 && y < data->y_max && x >= 0 && x < data->x_max &&
        data->i_maze[y][x] == 0)
        return (0);
    else
        return (84);
}

void create_final_maze(data_t *data, list_t *list)
{
    intersection_t *temp = list->head;

    for (int i = 0; i < data->y_max; ++i) {
        for (int y = 0; y < data->x_max; ++y) {
            if (data->i_maze[i][y] == 1)
                printf("X");
            if (data->i_maze[i][y] == 2 || data->i_maze[i][y] == 0)
                printf("*");
            if (data->i_maze[i][y] == 3)
                printf("o");
        }
        if (i < data->y_max - 1)
            printf("\n");
    }
}
