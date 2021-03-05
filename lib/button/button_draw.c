/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw button
*/

#include <button.h>

void button_draw(sfRenderWindow *window, button_t *button)
{
    if (button && button->button_s)
        sfRenderWindow_drawSprite(window, button->button_s, NULL);
}
