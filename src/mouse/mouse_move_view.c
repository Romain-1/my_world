/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** mouse_move_view
*/

#include <world.h>

void mouse_move_view(sfVector2i mouse, sfView *view, float fps)
{
    if (mouse.x < 1)
        sfView_move(view, (sfVector2f){-500.0f / fps, 0});
    if (mouse.x > WIDTH - 10)
        sfView_move(view, (sfVector2f){500.0f / fps, 0});
    if (mouse.y < 1)
        sfView_move(view, (sfVector2f){0, -500.0f / fps});
    if (mouse.y > HEIGHT - 10)
        sfView_move(view, (sfVector2f){0, 500.0f / fps});
}
