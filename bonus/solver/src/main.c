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

    if (ac == 3 && my_strcmp(av[2], "-CSFML") == 0) {
        data->lib = 1;
    } else if (ac == 3 && my_strcmp(av[2], "-SDL") == 0)
        data->lib = 2;
    if (ac == 2 || ac == 3)
        solver_manager(av, data);
    else
        return (84);

    return (0);
}