/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu display
*/

#include <menu.h>

static void button_sm_adapt(menu_scrolling_t *menu)
{
    sfIntRect rect_pos_s = sfSprite_getTextureRect
        (menu->button_tools[0]->button_s);
    sfIntRect rect_pos_m = sfSprite_getTextureRect
        (menu->button_tools[1]->button_s);

    if (menu->slide_bar->volume_s == 0)
        rect_pos_s.top = 210;
    else
        rect_pos_s.top = 0;
    if (menu->slide_bar->volume_m == 0)
        rect_pos_m.top = 210;
    else
        rect_pos_m.top = 0;
    sfSprite_setTextureRect(menu->button_tools[0]->button_s, rect_pos_s);
    sfSprite_setTextureRect(menu->button_tools[1]->button_s, rect_pos_m);
}

static void menu_scrolling_display
    (sfRenderWindow *window, menu_scrolling_t *menu)
{
    button_draw(window, menu->main_button);
    if (menu->button_on_off) {
        sfRenderWindow_drawRectangleShape(window, menu->shape, NULL);
        if (menu->txt_box)
            txt_box_display(window, menu->txt_box);
        if (menu->slide_bar) {
            button_sm_adapt(menu);
            slidebar_display(window, menu->slide_bar);
        }
        for (int i = 0; menu->button_tools[i]; i++)
            button_draw(window, menu->button_tools[i]);
    }
    for (int i = 0; menu->button_tools[i]; i++)
        if (menu->button_tools[i]->is_holded && menu->button_on_off)
            sfRenderWindow_drawText
            (window, menu->button_tools[i]->description, NULL);
}

void menu_display(sfRenderWindow *window, menu_t *menu)
{
    menu_scrolling_display(window, menu->tools_menu);
    menu_scrolling_display(window, menu->save_menu);
    menu_scrolling_display(window, menu->sound_menu);
    menu_map_size_display(window, menu->map_size);
}
