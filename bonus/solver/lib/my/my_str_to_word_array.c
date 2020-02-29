/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int how_many_words(const char *str)
{
    int count_word = 0;

    for (int i = 0; str[i]; ++i)
        if (str[i] == '\n')
            ++count_word;
    return (++count_word);
}

int len_word(const char *str)
{
    int len = 0;

    while (str[len] != '\0') {
        if (str[len] == '\n')
            break;
        ++len;
    }
    return (len);
}

char **my_str_to_word_array(const char *str, data_t *data)
{
    int y_max = how_many_words(str);
    char **tab = malloc(sizeof(char *) * (y_max + 1));
    int i = 0;
    int j = 0;
    int a = 0;
    int x_max = len_word(str);

    data->x_max = x_max;
    data->y_max = y_max;
    for (; i < y_max; ++i) {
        tab[i] = malloc(sizeof(char) * (x_max + 1));
        for (j = 0; j < x_max; ++a, ++j)
            tab[i][j] = str[a];
        ++a;
        tab[i][j] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}