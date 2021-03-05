/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu destroy
*/

#include <menu.h>

static void menu_scolling_destroy(menu_scrolling_t *menu)
{
    button_destroy(menu->main_button);
    for (int i = 0; menu->button_tools[i]; i++)
        button_destroy(menu->button_tools[i]);
    sfRectangleShape_destroy(menu->shape);
    if (menu->txt_box)
        txt_box_destroy(menu->txt_box);
    if (menu->slide_bar)
        slidebar_destroy(menu->slide_bar);
}

void menu_destroy(menu_t *menu)
{
    menu_scolling_destroy(menu->tools_menu);
    menu_scolling_destroy(menu->save_menu);
    menu_scolling_destroy(menu->sound_menu);
}
