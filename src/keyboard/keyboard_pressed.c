/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** keyboard_pressed
*/

#include <world.h>

static void rotation_event(world_t *world)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        matrix_rotateX(world->map->matrix, 100.0f / world->fps->nb);
        world->map->is_modified = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        matrix_rotateY(world->map->matrix, 100.0f / world->fps->nb);
        world->map->is_modified = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        matrix_rotateZ(world->map->matrix, 100.0f / world->fps->nb);
        world->map->is_modified = true;
    }
}

void keyboard_pressed(world_t *world)
{
    rotation_event(world);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        sfView_move(world->view_map, (sfVector2f){-500.0f / world->fps->nb, 0});
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        sfView_move(world->view_map, (sfVector2f){500.0f / world->fps->nb, 0});
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        sfView_move(world->view_map, (sfVector2f){0, -500.0f / world->fps->nb});
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        sfView_move(world->view_map, (sfVector2f){0, 500.0f / world->fps->nb});
    if (sfKeyboard_isKeyPressed(sfKeyLControl)
        && sfKeyboard_isKeyPressed(sfKeyR)) {
        sfView_reset(world->view_map, (sfFloatRect){-(float)WIDTH / 2.0f,
                    -(float)HEIGHT / 2.0f, WIDTH, HEIGHT});
        matrix_reset(world->map->matrix);
    }
}
