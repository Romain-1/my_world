/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_getnbr
*/

#include <my_libc.h>

int my_atoi(char const *s)
{
    int i = 0;
    int nb = 0;

    if (!s)
        return (0);
    for (; s[i] && !IS_NB(s[i]); i++);
    for (int j = i; s[j] && IS_NB(s[j]); j++) {
        nb *= 10;
        nb += s[j] - '0';
    }
    return ((i && s[i - 1] == '-') ? (-nb) : (nb));
}
