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
    int lib = 0;

    if (ac == 1 || (ac == 2 && !my_strcmp(av[1], "-h")))
        print_usage();
    if (ac == 3)
        imp = 1;
    if (ac == 4 && my_strcmp(av[3], "perfect"))
        return (84);
    if (ac == 4 && !my_strcmp(av[3], "imperfect"))
        imp = 1;
    if (ac == 5 && !my_strcmp(av[4], "-SDL"))
        lib = 1;
    if (ac == 5 && !my_strcmp(av[4], "-CSFML"))
        lib = 2;
    create_perfect(av, imp, lib);
}

void print_usage(void)
{
    my_putstr("USAGE: ./generator width height [perfect] -graphic\n\n");
    my_putstr("OPTIONS:\n\twidth: an integer value, between 0 and 100 for ");
    my_putstr("graphic.\n\theight: an integer value, between 0 and 100 for ");
    my_putstr("graphic.\n\tperfect: generate a perfect maze; default: ");
    my_putstr("imperfect.\n\tgraphic: two flags are available: SDL, CSFML. ");
    my_putstr("Only work with perfect mazes.\n");
    exit(0);
}

void final_disp(data_t *data)
{
    if (data->imp == 1)
        imperfect_it(data);
    print_tab(data->map);
    free_struct(data);
    exit(0);
}