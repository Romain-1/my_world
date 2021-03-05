/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** button destroy
*/

#include <button.h>

void button_destroy(button_t *button)
{
    sfSprite_destroy(button->button_s);
    sfText_destroy(button->description);
}
