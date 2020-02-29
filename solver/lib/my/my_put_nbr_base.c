/*
** EPITECH PROJECT, 2018
** put_nbr_base
** File description:
** pu_nbr_base
*/

#include "my.h"

int my_put_nbr_base(unsigned int nb, char *base)
{
    int len_base = 0;

    len_base = my_strlen(base);
    if (nb >= len_base)
        my_put_nbr_base(nb / len_base, base);
    my_putchar(base[nb % len_base]);
    return (0);
}
