/*
** EPITECH PROJECT, 2020
** my_libc
** File description:
** my_putfloat
*/

#include <my_libc.h>
#include <unistd.h>

void my_putfloat(int fd, float nb)
{
    my_putnbr(fd, nb);
    nb -= (int)nb;
    write(fd, ".", 1);
    if (nb < 0)
        nb *= -1;
    for (int i = 0; i < 6; i++) {
        nb *= 10.0f;
        if (nb < 1.0f)
            write(fd, "0", 1);
    }
    my_putnbr(fd, nb);
}
