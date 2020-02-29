/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line.c
*/

#include "my.h"

char *my_strcat_free(char *dest, char *src)
{
    int a = my_strlen(dest);
    char *new =  malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    for (int i = 0; dest != NULL && dest[i]; i++)
        new[i] = dest[i];
    for (int i = 0; src != NULL && src[i]; i++) {
        new[a] = src[i];
        a++;
    }
    if (dest != NULL)
        free(dest);
    new[a] = '\0';
    return (new);
}

char *get_next_line(int fd)
{
    char *str = NULL;
    char *buff = malloc(sizeof(char) * 2);
    int boolean = 0;
    int value = 0;

    while (boolean == 0) {
        value = read(fd, buff, 1);
        buff[value] = '\0';
        if (buff[0] == '\0')
            break;
        if (value <= 0)
            return (NULL);
        if (buff[0] == '\n')
            boolean = 1;
        else
            str = my_strcat_free(str, buff);
    }
    free(buff);
    return (str);
}
