/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu size map
*/

#include <menu_map_size.h>
#include <menu.h>
#include <txt_box.h>
#include <my_libc.h>

static void menu_map_size_button_create
    (menu_map_size_t *map_size, sfTexture *texture)
{
    map_size->button[DOWN_LEFT] = button_create
        (texture, TEXTURE_POSITION_DOWN_LEFT_BUTTON,
        (void *)&down_x, POS_SCALE_DOWN_LEFT_BUTTON);
    map_size->button[DOWN_RIGHT] = button_create
        (texture, TEXTURE_POSITION_DOWN_RIGHT_BUTTON,
        (void *)&down_y, POS_SCALE_DOWN_RIGHT_BUTTON);
    map_size->button[UP_LEFT] = button_create
        (texture, TEXTURE_POSITION_UP_LEFT_BUTTON,
        (void *)&up_x, POS_SCALE_UP_LEFT_BUTTON);
    map_size->button[UP_RIGHT] = button_create
        (texture, TEXTURE_POSITION_UP_RIGHT_BUTTON,
        (void *)&up_y, POS_SCALE_UP_RIGHT_BUTTON);
}

static void menu_map_size_fill_txt_box(menu_map_size_t *map_size)
{
    map_size->txt_box_left = txt_box_create
        ("resources/box.png", TXT_BOX_LEFT_POS_SCALE,
        SPRITE_RECT_SAVE_TXT_BOX);
    map_size->txt_box_right = txt_box_create
        ("resources/box.png", TXT_BOX_RIGHT_POS_SCALE,
        SPRITE_RECT_SAVE_TXT_BOX);
    map_size->txt_box_left->is_only_nb = 1;
    map_size->txt_box_right->is_only_nb = 1;
    map_size->txt_box_left->limit_char = 3;
    map_size->txt_box_left->nb_char = 2;
    map_size->txt_box_right->limit_char = 3;
    map_size->txt_box_right->nb_char = 2;
}

menu_map_size_t *menu_size_map_create(sfTexture *texture)
{
    menu_map_size_t *map_size = malloc(sizeof(menu_map_size_t));

    map_size->new_map_size_function = &world_modify_size;
    map_size->size = (sfVector2i){2, 2};
    menu_map_size_fill_txt_box(map_size);
    map_size->str[X] = map_size->txt_box_left->buffer;
    map_size->str[Y] = map_size->txt_box_right->buffer;
    map_size->txt_box_left->buffer = my_int_to_array(map_size->size.x);
    map_size->txt_box_right->buffer = my_int_to_array(map_size->size.y);
    menu_map_size_button_create(map_size, texture);
    map_size->shape = shape_create
        (MAP_SIZE_SHAPE_POSITION, MAP_SIZE_SHAPE_SCALE);
    map_size->txt_box_left->size_map_function = &world_modify_size;
    map_size->txt_box_right->size_map_function = &world_modify_size;
    return (map_size);
}
