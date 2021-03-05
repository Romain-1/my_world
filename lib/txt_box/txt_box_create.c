/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** txt_box_create
*/

#include <txt_box.h>

static void txt_box_fill_struct(txt_box_t *txt_box,
                                    sfVector2f const *pos_scale)
{
    txt_box->position = pos_scale[0];
    txt_box->scale = pos_scale[1];
    txt_box->txt_box_hold = 0;
    txt_box->nb_char = 0;
    txt_box->buffer = malloc(sizeof(char) * 32);
    txt_box->buffer[0] = '\0';
    txt_box->cursor_clock = sfClock_create();
    txt_box->size_map_function = NULL;
}

static void txt_box_fill_sprite
    (char *filepath, txt_box_t *txt_box, sfIntRect const pos_rect)
{
    txt_box->txt_box_s = sfSprite_create();
    txt_box->cursor = sfSprite_create();
    txt_box->texture_txt_box = sfTexture_createFromFile(filepath, &pos_rect);
    txt_box->texture_cursor = sfTexture_createFromFile
                                            ("resources/cursor.png", NULL);
    sfSprite_setTexture(txt_box->cursor, txt_box->texture_cursor, sfTrue);
    sfSprite_setTexture(txt_box->txt_box_s, txt_box->texture_txt_box, sfTrue);
    sfSprite_setScale(txt_box->txt_box_s, txt_box->scale);
    sfSprite_setPosition(txt_box->txt_box_s, txt_box->position);
}

txt_box_t *txt_box_create(char *filepath,
    sfVector2f const *pos_scale, sfIntRect const pos_rect)
{
    txt_box_t *txt_box = malloc(sizeof(txt_box_t));

    if (!txt_box)
        return (NULL);
    txt_box_fill_struct(txt_box, pos_scale);
    txt_box_fill_sprite(filepath, txt_box, pos_rect);
    return (txt_box);
}
