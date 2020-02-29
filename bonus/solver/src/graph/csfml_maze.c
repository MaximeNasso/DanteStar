/*
** EPITECH PROJECT, 2019
** generator
** File description:
** TODO: add description
*/

#include "my.h"

void draw_map(data_t *data, sfRenderWindow *win, sfRectangleShape *dig)
{
    for (int j = 0; j < data->y_max; j++) {
        for (int i = 0; i < data->x_max; i++) {
            if (data->i_maze[j][i] == 0) {
                sfRectangleShape_setFillColor(dig, sfWhite);
                sfRectangleShape_setSize(dig, (sfVector2f) {10, 10});
                sfRectangleShape_setPosition(dig, (sfVector2f) {j * 10, i * 10});
            }
            if (data->i_maze[j][i] == 3) {
                sfRectangleShape_setFillColor(dig, sfRed);
                sfRectangleShape_setSize(dig, (sfVector2f) {10, 10});
                sfRectangleShape_setPosition(dig, (sfVector2f) {j * 10, i * 10});
            }
            if (data->i_maze[j][i] == 2) {
                sfRectangleShape_setFillColor(dig, sfWhite);
                sfRectangleShape_setSize(dig, (sfVector2f) {10, 10});
                sfRectangleShape_setPosition(dig, (sfVector2f) {j * 10, i * 10});
            }
            sfRenderWindow_drawRectangleShape(win, dig, NULL);
            sfRenderWindow_display(win);
        }
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