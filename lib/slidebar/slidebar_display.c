/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slidebar display
*/

#include <slidebar.h>

void slidebar_display(sfRenderWindow *window, slidebar_t *slide_bar)
{
    sfRenderWindow_drawSprite(window, slide_bar->background, NULL);
    sfRenderWindow_drawSprite(window, slide_bar->slide_bar, NULL);
}
