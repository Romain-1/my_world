/*
** EPITECH PROJECT, 2020
** my_libc
** File description:
** my_int_to_array
*/

#include <stdlib.h>

char *my_int_to_array(int nb)
{
    int nb_cpy = nb;
    char *str = NULL;
    int i = 0;

    for (i = 0; nb_cpy > 0; i++)
        nb_cpy /= 10;
    str = malloc(sizeof(char) * (i + 32));
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    str[i] = '\0';
    i--;
    for (; i >= 0; i--) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    return (str);
}
