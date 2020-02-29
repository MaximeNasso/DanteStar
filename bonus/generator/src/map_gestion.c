/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** TODO: add description
*/

#include "generator.h"

char *create_empty_line(int width)
{
    char *to_return = malloc(sizeof(int) * (width + 1));

    for (int i = 0; i < width; i++)
        to_return[i] = 'X';
    to_return[width] = '\0';
    return (to_return);
}

char **create_map(int x, int y)
{
    char **to_return = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i < y; i++)
        to_return[i] = create_empty_line(x);
    to_return[0][0] = '*';
    to_return[y] = NULL;
    return (to_return);
}