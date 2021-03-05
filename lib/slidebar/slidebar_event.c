/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slidebar event
*/

#include <slidebar.h>

void slidebar_event
    (sfRenderWindow *window, slidebar_t *slide_bar)
{
    sfIntRect rect_pos = sfSprite_getTextureRect(slide_bar->slide_bar);
    sfVector2i position_m = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds_s = sfSprite_getGlobalBounds(slide_bar->background);
    sfVector2f scale = sfSprite_getScale(slide_bar->slide_bar);

    if (sfMouse_isButtonPressed(sfMouseLeft)
    && button_is_hold(position_m, bounds_s)) {
        rect_pos.width = ((position_m.x - bounds_s.left) * (1 / scale.x));
        sfSprite_setTextureRect(slide_bar->slide_bar, rect_pos);
        slidebar_getvalue_s(slide_bar);
        slidebar_getvalue_m(slide_bar);
    }
}
