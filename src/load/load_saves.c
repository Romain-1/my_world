/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** load_saves
*/

#include <stdio.h>
#include <saved.h>
#include <sys/types.h>
#include <dirent.h>
#include <my_libc.h>
#include <get_next_line.h>

static void add_save(saved_t *saves, struct dirent *dirent)
{
    char *filepath = my_strcat("resources/saves/", dirent->d_name);
    char **word_array = NULL;
    char *str = NULL;
    char *image_path = NULL;
    size_t size = 0;
    FILE *fd = NULL;

    fd = fopen(filepath, "r");
    if (!fd)
        return;
    getline(&str, &size, fd);
    word_array = my_str_to_word_array(str, " \n");
    image_path = my_strdup(word_array[1]);
    saves->paths[saves->length] = filepath;
    saves->textures[saves->length] = sfTexture_createFromFile(image_path, NULL);
    sfSprite_setTexture(saves->sprites[saves->length],
                        saves->textures[saves->length], sfTrue);
    sfSprite_setScale(saves->sprites[saves->length], (sfVector2f){0.2, 0.2});
    saves->length++;
    fclose(fd);
}

static saved_t *saves_malloc(void)
{
    DIR *dir = opendir("resources/saves/");
    saved_t *saves = malloc(sizeof(saved_t));
    struct dirent *dirent = NULL;
    size_t len = 0;

    if (!dir || !saves)
        return (NULL);
    for (dirent = readdir(dir); dirent; dirent = readdir(dir)) {
        if (dirent->d_name[0] != '.')
            len++;
    }
    saves->textures = malloc(sizeof(sfTexture *) * len);
    saves->sprites = malloc(sizeof(sfSprite *) * len);
    for (int i = 0; i < len; i++)
        saves->sprites[i] = sfSprite_create();
    saves->paths = malloc(sizeof(char *) * len);
    saves->length = 0;
    closedir(dir);
    return (saves);
}

saved_t *load_saves(void)
{
    saved_t *saves = saves_malloc();
    DIR *dir = NULL;
    struct dirent *dirent = NULL;
    sfTexture *texture = sfTexture_createFromFile
        ("resources/create_new_map.png", NULL);

    if (!saves)
        return (NULL);
    dir = opendir("resources/saves");
    dirent = readdir(dir);
    while (dirent) {
        if (dirent->d_name[0] != '.')
            add_save(saves, dirent);
        dirent = readdir(dir);
    }
    closedir(dir);
    saves->button_new_map = button_create(texture, RECT_POS_BUTTON_CREATE,
                                            NULL, POS_SCALE_BUTTON_CREATE);
    return (saves);
}
