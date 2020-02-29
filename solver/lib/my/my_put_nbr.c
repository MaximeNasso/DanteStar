/*
** EPITECH PROJECT, 2018
** day3
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int count = 0;

    for (int j = nb; j > 9; count++)
        j /= 10;
    count++;
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    } else {
        my_putchar((nb % 10) + 48);
    }
    return (count);
}
