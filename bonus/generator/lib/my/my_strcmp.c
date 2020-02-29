/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my_strcmp
*/

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' || str2[i] != '\0')
        if (str1[i] > str2[i])
            return (str1[i] - str2[i]);
        else if (str1[i] < str2[i])
            return (str1[i] - str2[i]);
        else
            i++;
    return (0);
}
