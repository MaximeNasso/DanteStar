/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line.c
*/

#include "my.h"

char *get_next_line(int fd)
{
    char *str = NULL;
    char *buff = malloc(sizeof(char) * 2);
    int boolean = 0;
    int value = 0;

    while (boolean == 0) {
        value = read(fd, buff, 1);
        buff[value] = '\0';
        if (value <= 0)
            return (NULL);
        if (buff[0] == '\n')
            boolean = 1;
        else
            str = my_strcat(str, buff);
    }
    free(buff);
    return (str);
}
