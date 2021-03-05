/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu mouse hover
*/

#include <menu.h>

static void menu_scrolling_mouse_hover
    (sfRenderWindow *window, menu_scrolling_t *menu)
{
    button_on_hold(window, menu->main_button);
    for (size_t i = 0; menu->button_tools[i]; i++)
        button_on_hold(window, menu->button_tools[i]);
    if (menu->slide_bar && menu->button_on_off)
        slidebar_event(window, menu->slide_bar);
}

void menu_mouse_hover(sfRenderWindow *window, menu_t *menu)
{
    menu_scrolling_mouse_hover(window, menu->tools_menu);
    menu_scrolling_mouse_hover(window, menu->save_menu);
    menu_scrolling_mouse_hover(window, menu->sound_menu);
    for (int i = 0; i < 4; i++)
        button_on_hold(window, menu->map_size->button[i]);
    menu_map_size_update(menu->map_size);
}
