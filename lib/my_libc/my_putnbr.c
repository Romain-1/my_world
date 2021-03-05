/*
** EPITECH PROJECT, 2020
** my_libc
** File description:
** my_putnbr
*/

#include <unistd.h>

void my_putnbr(int fd, int nb)
{
    char c = nb + '0';

    if (nb < 0) {
        write(fd, "-", 1);
        my_putnbr(fd, -nb);
    } else if (nb > 9) {
        my_putnbr(fd, nb / 10);
        my_putnbr(fd, nb % 10);
    } else
        write(fd, &c, 1);
}
