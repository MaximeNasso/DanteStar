/*
** EPITECH PROJECT, 2019
** lib
** File description:
** convert_nb_base.c
*/

#include "my.h"

int len_nb(int nb, int len_base)
{
    int i = 0;

    while (nb >= len_base) {
        nb = nb / len_base;
        i++;
    }
    i++;
    return (i);
}

int convert_nb_base(int nb, char *base)
{
    int len_base = my_strlen(base);
    char *str = malloc(sizeof(char) * len_nb(nb, len_base) + 1);
    int i = 0;
    int nb_temp = nb;
    int result_final = 0;

    while (nb >= len_base) {
        str[i] = base[nb % len_base];
        nb = nb / len_base;
        i++;
    }
    str[i] = base[nb % len_base];
    str[len_nb(nb_temp, len_base)] = '\0';
    str = my_revstr(str);
    result_final = my_getnbr(str);
    free(str);
    return (result_final);
}
