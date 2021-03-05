/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** shape shape create
*/

#include <menu.h>

sfRectangleShape *shape_create
    (sfVector2f const position, sfVector2f const scale)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, MENU_BG_COLOR);
    sfRectangleShape_setSize(shape, scale);
    sfRectangleShape_setPosition(shape, position);
    return (shape);
}
