/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu size map display
*/

#include <menu_map_size.h>

void menu_map_size_display(sfRenderWindow *window, menu_map_size_t *map_size)
{
    sfRenderWindow_drawRectangleShape(window, map_size->shape, NULL);
    txt_box_display(window, map_size->txt_box_left);
    txt_box_display(window, map_size->txt_box_right);
    for (int i = 0; i < 4; i++)
        button_draw(window, map_size->button[i]);
}
