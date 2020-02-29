/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    data_t *data = init_data();

    if (ac == 2)
        solver_manager(av, data);
    else
        return (84);

    return (0);
}