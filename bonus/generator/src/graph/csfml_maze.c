/*
** EPITECH PROJECT, 2019
** generator
** File description:
** TODO: add description
*/

#include "generator.h"

void draw_end_csfml(data_t *data, sfRenderWindow *win, sfRectangleShape *dig)
{
    sfVector2f vec = {0, 0};

    usleep(25000);
    if (data->end == 1) {
        vec.y = (data->y - 2) * 10;
        vec.x = (data->x - 1) * 10;
    }
    if (data->end == 2) {
        vec.x = (data->x - 1) * 10;
        vec.y = (data->y - 2) * 10;
    }
    if (data->end == 3) {
        vec.x = (data->x - 2) * 10;
        vec.y = (data->y - 1) * 10;
    }
    sfRectangleShape_setPosition(dig, vec);
    sfRenderWindow_drawRectangleShape(win, dig, NULL);
    usleep(25000);
    vec.x = (data->x - 1) * 10;
    vec.y = (data->y - 1) * 10;
    sfRectangleShape_setPosition(dig, vec);
}

void game_loop_csfml(data_t *data, sfRenderWindow *window, sfRectangleShape
*dig, sfEvent event)
{
    int done = 0;

    while (sfRenderWindow_isOpen(window)) {
        if (!data->pos->first->next && data->done == 1) {
            sleep(2);
            sfRenderWindow_close(window);
        }
        if (data->end != 0 && done == 0) {
            draw_end_csfml(data, window, dig);
            done = 1;
        }
        sfRenderWindow_pollEvent(window, &event);
        sfRenderWindow_drawRectangleShape(window, dig, NULL);
        sfRenderWindow_display(window);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        usleep(25000);
        dig_maze(data);
        sfRectangleShape_setPosition(dig, (sfVector2f) {data->c * 10, data->r
                    * 10});
    }
}

sfRenderWindow *my_window(unsigned int widht, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = widht;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode,
        "Maze generator graphical version: CSFML", sfDefaultStyle, NULL);
    return (window);
}

void csfml_display(data_t *data)
{
    sfRenderWindow *window = my_window(data->x * 10, data->y * 10);
    sfEvent event;
    sfRectangleShape *dig;

    dig = sfRectangleShape_create();
    sfRectangleShape_setFillColor(dig, sfWhite);
    sfRectangleShape_setSize(dig, (sfVector2f) {10, 10});
    sfRectangleShape_setPosition(dig, (sfVector2f) {0, 0});
    game_loop_csfml(data, window, dig, event);
    sfRenderWindow_destroy(window);
}