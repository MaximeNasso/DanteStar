/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str != NULL && str[i] != '\0') {
        i++;
    }
    return (i);
}
