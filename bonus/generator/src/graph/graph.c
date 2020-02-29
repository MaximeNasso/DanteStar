/*
** EPITECH PROJECT, 2019
** generator
** File description:
** TODO: add description
*/

#include "generator.h"

void graphical_maze(data_t *data)
{
    switch (data->lib) {
        case 1:
            sdl_display(data);
            break;
        case 2:
            csfml_display(data);
            break;
    }
}