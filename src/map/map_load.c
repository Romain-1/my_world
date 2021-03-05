/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_load
*/

#include <my_libc.h>
#include <unistd.h>
#include <stdio.h>
#include <map.h>

static void map_fill(map_t *map, FILE *fd)
{
    char *str = NULL;
    size_t bufsize = 0;
    ssize_t size = 0;
    char **word_array = NULL;
    int j = 0;
    int i = 0;

    for (; i <= map->size.y; i++) {
        size = getline(&str, &bufsize, fd);
        if (size == -1)
            break;
        word_array = my_str_to_word_array(str, " \n");
        for (j = 0; word_array && word_array[j]; j++)
            map->map_2d[i][j] = my_atof(word_array[j]);
        for (; j <= map->size.x; j++)
            map->map_2d[i][j] = 0.0f;
    }
    for (; i <= map->size.y; i++)
        for (j = 0; j <= map->size.x; j++)
            map->map_2d[i][j] = 0.0f;
}

static sfVector2i get_size(FILE *fd)
{
    sfVector2i size = {-1, -1};
    char *str = NULL;
    char **word_array = NULL;
    size_t bufsize = 0;
    size_t len = 0;

    getline(&str, &bufsize, fd);
    word_array = my_str_to_word_array(str, " \n");
    for (; word_array && word_array[len]; len++);
    if (len < 4)
        return (size);
    if (!my_strcmp(word_array[0], "Lines:"))
        size.y = my_atoi(word_array[1]);
    if (!my_strcmp(word_array[2], "Columns:"))
        size.x = my_atoi(word_array[3]);
    return (size);
}

static int get_seed(FILE *fd)
{
    size_t bufsize = 0;
    char *str = NULL;
    char **word_array = NULL;

    getline(&str, &bufsize, fd);
    getline(&str, &bufsize, fd);
    word_array = my_str_to_word_array(str, " \n");
    if (word_array && !my_strcmp(word_array[0], "Seed:"))
        return (my_atoi(word_array[1]));
}

map_t *map_load(char const *filepath)
{
    FILE *fd = NULL;
    map_t *new_map = NULL;
    sfVector2i size;
    int seed = 0;

    if (filepath)
        fd = fopen(filepath, "r");
    if (!fd)
        return (NULL);
    seed = get_seed(fd);
    size = get_size(fd);
    if (size.x == -1)
        return (NULL);
    new_map = map_create(size);
    new_map->seed = seed;
    map_fill(new_map, fd);
    fclose(fd);
    return (new_map);
}
