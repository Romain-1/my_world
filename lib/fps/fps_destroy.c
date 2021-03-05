/*
** EPITECH PROJECT, 2020
** fps
** File description:
** fps_destroy
*/

#include <fps.h>
#include <stdlib.h>

void fps_destroy(fps_t *fps)
{
    sfText_destroy(fps->text);
    sfFont_destroy(fps->font);
    free(fps->str);
    free(fps);
}
