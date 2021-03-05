/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** main
*/

#include <world.h>
#include <my_libc.h>

int main(int ac, char **av, char **ae)
{
    if (!ae || !ae[0])
        return (84);
    if (ac > 1 && !my_strcmp(av[1], "-h"))
        help(av[0]);
    return (world_loop(av[1]));
}
