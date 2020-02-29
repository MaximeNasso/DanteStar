/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** TODO: add description
*/

#include "generator.h"

void check_line(data_t *data, int index)
{
    for (int i = 0; data->map[index][i]; ++i) {
        if (data->map[index + 1] && index - 1 > 0
            && data->map[index - 1][i] == '*'
            && data->map[index + 1][i] == '*'
            && data->map[index][i + 1] == 'X'
            && data->map[index][i - 1] == 'X') {
            data->map[index][i] = '*';
        }
    }
}

void imperfect_it(data_t *data)
{
    for (int i = 0; i < data->y; ++i)
        check_line(data, i);
}