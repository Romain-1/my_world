/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** help
*/

#include <my_libc.h>

static void usage(char const *bin_name)
{
    my_puts(1, "USAGE\n\t");
    my_puts(1, bin_name);
    my_puts(1, " [ -h | path_to_map ]\n");
    my_puts(1, "\t-h\t\tDisplay help and quit.\n");
    my_puts(1, "\tpath_to_map\tThe path to a map to load at the start");
    my_puts(1, " of the game.\n");
}

void help(char const *bin_name)
{
    my_puts(1, "My world: terraformer program.\n\n");
    usage(bin_name);
}
