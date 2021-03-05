/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu event
*/

#include <menu.h>

bool menu_event_scrolling
    (sfRenderWindow *window, menu_scrolling_t *menu,
        sfEvent event, void *world)
{
    bool button_pressed = false;

    button_pressed = button_on_click(window, event, menu->main_button, menu);
    if (button_pressed == true)
        return (true);
    for (int i = 0; menu->button_tools[i] && menu->button_on_off; i++) {
        button_pressed = button_on_click
        (window, event, menu->button_tools[i], world);
        if (button_pressed == true)
            return (true);
    }
    if (menu->txt_box)
        txt_box_manage_event(window, event, menu->txt_box, world);
    return (false);
}

bool menu_event_scrolling2(sfRenderWindow *window, menu_scrolling_t *menu,
                            sfEvent event, void *world)
{
    bool button_pressed = false;

    button_pressed = button_on_click(window, event, menu->main_button, menu);
    if (button_pressed == true)
        return (true);
    button_pressed = button_on_click
        (window, event, menu->button_tools[0], world);
    if (button_pressed == true)
        return (true);
    if (menu->txt_box)
        txt_box_manage_event(window, event, menu->txt_box, world);
    return (false);
}

void menu_event(sfRenderWindow *window, menu_t *menu,
    sfEvent event, void *world)
{
    menu->button_pressed = menu_event_scrolling
        (window, menu->tools_menu, event, world);
    if (menu->button_pressed == true)
        return;
    menu->button_pressed = menu_event_scrolling2
        (window, menu->save_menu, event, world);
    if (menu->button_pressed == true)
        return;
    menu->button_pressed = menu_event_scrolling
        (window, menu->sound_menu, event, world);
    if (menu->button_pressed == true)
        return;
    for (int i = 0; i < 4; i++)
        menu->button_pressed = button_on_click
            (window, event, menu->map_size->button[i], world);
    txt_box_manage_event(window, event, menu->map_size->txt_box_left, world);
    txt_box_manage_event(window, event, menu->map_size->txt_box_right, world);
}
