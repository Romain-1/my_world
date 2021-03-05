/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** fps_create
*/

#include <fps.h>
#include <stdlib.h>

fps_t *fps_create(void)
{
    fps_t *fps = malloc(sizeof(fps_t));

    fps->str = malloc(sizeof(char) * (10 + 1));
    for (size_t i = 0; i <= 10; i++)
        fps->str[i] = 0;
    fps->text = sfText_create();
    fps->clock = sfClock_create();
    return (fps);
}
