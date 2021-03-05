/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu size map update
*/

#include <menu_map_size.h>

void menu_map_size_update(menu_map_size_t *map_size)
{
    if (map_size->txt_box_left->buffer[0] == '0'
    || map_size->txt_box_left->buffer[0] == '\0')
        map_size->txt_box_left->buffer[0] = '1';
    if (map_size->txt_box_right->buffer[0] == '0'
    || map_size->txt_box_right->buffer[0] == '\0')
        map_size->txt_box_right->buffer[0] = '1';
    map_size->size.x = my_atoi(map_size->txt_box_left->buffer);
    map_size->size.y = my_atoi(map_size->txt_box_right->buffer);
}
