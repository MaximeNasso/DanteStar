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
    sfRenderWindow *window = NULL;
    sfEvent event;
    sfRectangleShape *dig = sfRectangleShape_create();
    if (data->lib == 1) {
        window = my_window(data->x_max * 10, data->y_max * 10);
        sfRectangleShape_setFillColor(dig, sfRed);
        sfRectangleShape_setSize(dig, (sfVector2f) {10, 10});
        sfRectangleShape_setPosition(dig, (sfVector2f) {0, 0});
        sfRenderWindow_drawRectangleShape(window, dig, NULL);
    }
    /*else if (data->lib == 2) {
        SDL_Surface *dig = NULL;
        SDL_Rect pos;
        SDL_Surface *bck = NULL;
        SDL_Init(SDL_INIT_VIDEO);
        pos.x = data->x;
        pos.y = data->y;
        bck = SDL_SetVideoMode(data->x_max * 10, data->y_max * 10, 32, SDL_HWSURFACE);
        SDL_WM_SetCaption("Maze generator graphical version: SDL", NULL);
        dig = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
        SDL_FillRect(bck, NULL, SDL_MapRGB(bck->format, 0, 0, 0));
        SDL_FillRect(dig, NULL, SDL_MapRGB(bck->format, 255, 255, 255));
    }*/
    check_start_end(data);
    solver_algo(data, window, event, dig);
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

int solver_algo(data_t *data, sfRenderWindow *window, sfEvent event,
                sfRectangleShape *dig)
{
    list_t *list = NULL;

    list = add_node(list, 0, 0);
    data->i_maze[0][0] = 3;
    solve_loop(data, list, window, event, dig);
    if (data->lib == 0)
        create_final_maze(data, list);
}

void solve_loop(data_t *data, list_t *list, sfRenderWindow *window,
                sfEvent event, sfRectangleShape *dig)
{
    while (42) {
        if (data->lib != 0) {
            usleep(100000);
            draw_map(data, window, dig);
        }
        if (data->y == data->y_max - 1 && data->x == data->x_max - 1) {
            sleep(2);
            if (data->lib != 0)
                sfRenderWindow_close(window);
            break;
        }
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