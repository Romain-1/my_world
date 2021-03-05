/*
** EPITECH PROJECT, 2020
** fps
** File description:
** fps_set_font
*/

#include <fps.h>

void fps_set_font(fps_t *fps, char const *filepath)
{
    fps->font = sfFont_createFromFile(filepath);
    sfText_setFont(fps->text, fps->font);
}
