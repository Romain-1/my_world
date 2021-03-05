/*
** EPITECH PROJECT, 2020
** my_libc
** File description:
** my_puts
*/

#include <my_libc.h>
#include <unistd.h>

void my_puts(int fd, char const *str)
{
    write(fd, str, my_strlen(str));
}
