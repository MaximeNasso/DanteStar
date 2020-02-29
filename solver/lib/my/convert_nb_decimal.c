/*
** EPITECH PROJECT, 2019
** lib
** File description:
** convert_nb_decimal.c
*/

int power(int nb, int pow)
{
    int result = 1;

    if (pow == 0)
        return (1);
    while (pow > 0) {
        result = result * nb;
        pow--;
    }
    return (result);
}

int convert_nb_decimal(int nb)
{
    int nb_temp = nb;
    int pow = 0;
    int temp = 0;
    int i = 0;
    int result = 0;

    while (nb > 0) {
        temp = nb % 10;
        nb = nb / 10;
        result += temp * (power(2, pow));
        pow++;
        i++;
    }
    return (result);
}
