/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** button on hold action
*/

#include <button.h>

void button_on_hold(sfRenderWindow *window, button_t *button)
{
    sfVector2i position_m = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds_s;
    sfVector2f position_t = {position_m.x, position_m.y};

    if (!button)
        return;
    position_t.x -= 30;
    position_t.y += 15;
    bounds_s = sfSprite_getGlobalBounds(button->button_s);
    sfText_setPosition(button->description, position_t);
    if (button_is_hold(position_m, bounds_s)) {
        button->is_holded = 1;
        sfSprite_setTextureRect(button->button_s, button->button_on_hold);
    } else {
        button->is_holded = 0;
        sfSprite_setTextureRect(button->button_s, button->button_idle);
    }
}
