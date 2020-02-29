/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main.c
*/

#include "generator.h"

int main(int ac, char **av)
{
    int imp = 0;

    if (ac == 3)
        imp = 1;
    if (ac == 4 && my_strcmp(av[3], "perfect"))
        return (84);
    if (ac == 4 && !my_strcmp(av[3], "imperfect"))
        imp = 1;
    create_perfect(av, imp);
}

void final_disp(data_t *data)
{
    if (data->imp == 1)
        imperfect_it(data);
    print_tab(data->map);
    free_struct(data);
    exit(0);
}