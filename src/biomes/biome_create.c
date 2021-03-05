/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** biome_create
*/

#include <my_libc.h>
#include <biome.h>
#include <get_next_line.h>

static void biome_set_default(biome_t *biome)
{
    biome->upper_factor = 500.0f;
    biome->lower_factor = 500.0f;
    biome->resolution = 20;
    biome->ground_height = 0;
}

static void biome_set(biome_t *biome, int fd)
{
    char **word_array = NULL;
    char *str = get_next_line(fd);

    while (str) {
        word_array = my_str_to_word_array(str, ":");
        if (!my_strcmp(word_array[0], "Upper part factor"))
            biome->upper_factor = my_atof(word_array[1]);
        if (!my_strcmp(word_array[0], "Lower part factor"))
            biome->lower_factor = my_atof(word_array[1]);
        if (!my_strcmp(word_array[0], "Ground height"))
            biome->ground_height = my_atof(word_array[1]);
        if (!my_strcmp(word_array[0], "Resolution"))
            biome->resolution = my_atof(word_array[1]);
        free(str);
        str = get_next_line(fd);
    }
}

biome_t *biome_create(char const *filepath)
{
    biome_t *biome = malloc(sizeof(biome_t));
    int fd = -1;

    if (!biome)
        return (NULL);
    biome_set_default(biome);
    if (filepath)
        fd = open(filepath, O_RDONLY);
    if (fd != -1) {
        biome_set(biome, fd);
        close(fd);
    }
    return (biome);
}
