/*
** EPITECH PROJECT, 2020
** my_libc
** File description:
** my_strcat
*/

#include <my_libc.h>
#include <stdlib.h>

char *my_strcat(char const *str1, char const *str2)
{
    char *new = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    size_t index = 0;

    if (!new)
        return (NULL);
    for (size_t i = 0; str1 && str1[i]; i++, index++)
        new[index] = str1[i];
    for (size_t i = 0; str2 && str2[i]; i++, index++)
        new[index] = str2[i];
    new[index] = 0;
    return (new);
}
