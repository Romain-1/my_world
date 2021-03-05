/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** button on click
*/

#include <button.h>

bool button_on_click
    (sfRenderWindow *window, sfEvent event, button_t *button, void *arg)
{
    sfVector2f scale = {0.9, 0.9};
    sfVector2i position_m = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds_s;

    if (!button)
        return (false);
    bounds_s = sfSprite_getGlobalBounds(button->button_s);
    if (event.type == sfEvtMouseButtonPressed
        && button_is_hold(position_m, bounds_s)) {
        sfSprite_scale(button->button_s, scale);
        if (button->function)
            button->function(arg);
        return (true);
    } else
        sfSprite_setScale(button->button_s, button->scale);
    return (false);
}
