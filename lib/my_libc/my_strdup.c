/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_strdup
*/

#include <my_libc.h>
#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *new = NULL;
    size_t i = 0;

    if (!str)
        return (NULL);
    new = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!new)
        return (NULL);
    for (; str[i]; i++)
        new[i] = str[i];
    new[i] = 0;
    return (new);
}
