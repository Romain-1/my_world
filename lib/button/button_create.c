/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create button
*/

#include <menu.h>

static void button_fill_struct(button_t *button, sfVector2f const *pos_scale,
    sfIntRect const *texture_rect, void (*function)(void *))
{
    button->button_on_hold = texture_rect[1];
    button->button_idle = texture_rect[0];
    button->position = pos_scale[0];
    button->scale = pos_scale[1];
    button->function = function;
}

static void button_fill_sprite(button_t *button, sfTexture *texture)
{
    sfVector2f origin;
    sfFloatRect bounds;

    button->button_s = sfSprite_create();
    button->button_texture = texture;
    sfSprite_setTexture(button->button_s, button->button_texture, sfTrue);
    sfSprite_setTextureRect(button->button_s, button->button_idle);
    bounds = sfSprite_getGlobalBounds(button->button_s);
    origin.x = bounds.width / 2;
    origin.y = bounds.height / 2;
    sfSprite_setOrigin(button->button_s, origin);
    sfSprite_setScale(button->button_s, button->scale);
    sfSprite_setPosition(button->button_s, button->position);
}

static void button_fill_text(button_t *button, char const *description_text)
{
    sfVector2f position = {0, 0};
    sfColor color = {200, 200, 200, 255};
    sfFont *font = sfFont_createFromFile("resources/arial.ttf");

    button->description = sfText_create();
    sfText_setCharacterSize(button->description, 30);
    sfText_setPosition(button->description, position);
    sfText_setFont(button->description, font);
    sfText_setColor(button->description, color);
    sfText_setString(button->description, description_text);
    button->is_holded = 0;
}

button_t *button_create(sfTexture *texture, sfIntRect const *texture_rect,
    void (*function)(void *), sfVector2f const *pos_scale)
{
    button_t *button = malloc(sizeof(button_t));
    static int nb_button = 0;

    if (!button || !pos_scale || !texture_rect || !texture) {
        return (NULL);
    }
    if (pos_scale[0].x == 1700 && pos_scale[0].y == 100)
        nb_button = 0;
    button_fill_struct(button, pos_scale, texture_rect, function);
    button_fill_sprite(button, texture);
    button_fill_text(button, BUTTON_TEXT_OVER[nb_button]);
    nb_button += 1;
    if (!BUTTON_TEXT_OVER[nb_button])
        nb_button = 0;
    return (button);
}
