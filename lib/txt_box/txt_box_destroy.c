/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** txt box destroy
*/

#include <txt_box.h>

void txt_box_destroy(txt_box_t *txt_box)
{
    sfSprite_destroy(txt_box->txt_box_s);
    sfSprite_destroy(txt_box->cursor);
    sfTexture_destroy(txt_box->texture_cursor);
    sfTexture_destroy(txt_box->texture_txt_box);
    sfClock_destroy(txt_box->cursor_clock);
}
