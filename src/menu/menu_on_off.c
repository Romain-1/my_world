/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu on off
*/

#include <menu.h>

void menu_on_off(menu_scrolling_t *menu)
{
    if (menu->button_on_off)
        menu->button_on_off = 0;
    else
        menu->button_on_off = 1;
}
