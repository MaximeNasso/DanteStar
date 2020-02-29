/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int a = my_strlen(dest);
    char *new =  malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    for (int i = 0; dest != NULL && dest[i]; i++)
        new[i] = dest[i];
    for (int i = 0; src != NULL && src[i]; i++) {
        new[a] = src[i];
        a++;
    }
    new[a] = '\0';
    return (new);
}
