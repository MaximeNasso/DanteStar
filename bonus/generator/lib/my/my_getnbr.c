/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr.c
*/

#include <stdio.h>

int my_strlen_nbr(char const *str)
{
    int i = 0;

    while ((str[i] >= '0' && str[i] <= '9')
            || str[i] == '-' || str[i] == '+') {
        i++;
    }
    return (i);
}

int my_strlen_nbr_bis(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        i++;
        count++;
    }
    return (count);
}

int my_power(int nb, int p)
{
    int resultat = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    while (p > 0) {
        p--;
        resultat = resultat * nb;
    }
    return (resultat);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int resultat = 0;
    int digit = 0;
    int counter = my_strlen_nbr_bis(str) - 1;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            neg *= -1;
    }
    while (i <= my_strlen_nbr(str) - 1) {
        if (str[i] >= '0' || str[i] <= '9') {
            digit = str[i] - '0';
            resultat += my_power(10, counter) * digit;
            i++;
            counter--;
        } else
            return (resultat);
    }
    return (resultat * neg);
}