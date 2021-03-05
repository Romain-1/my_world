/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** txt box display
*/

#include <txt_box.h>

static void txt_box_set_text(txt_box_t *txt_box)
{
    sfVector2f position = txt_box->position;

    position.x += 30 * txt_box->scale.x;
    position.y += 0 * txt_box->scale.y;
    txt_box->text = create_text
        ((sfColor){0, 0, 0, 255}, 50,
        position, txt_box->buffer);
}

static void txt_box_set_cursor(txt_box_t *txt_box)
{
    sfFloatRect bounds = sfText_getGlobalBounds(txt_box->text);
    sfVector2f pos =
    {bounds.left + bounds.width - 20, bounds.top + bounds.height - 20};
    sfVector2f scale = {0.2, 0.2};

    sfSprite_setPosition(txt_box->cursor, pos);
    sfSprite_setScale(txt_box->cursor, scale);
}

void txt_box_display(sfRenderWindow *window, txt_box_t *txt_box)
{
    sfTime time;

    txt_box_set_text(txt_box);
    txt_box_set_cursor(txt_box);
    sfRenderWindow_drawSprite(window, txt_box->txt_box_s, NULL);
    sfRenderWindow_drawText(window, txt_box->text, NULL);
    if (txt_box->txt_box_hold) {
        time = sfClock_getElapsedTime(txt_box->cursor_clock);
        if (time.microseconds <= 500000)
            sfRenderWindow_drawSprite(window, txt_box->cursor, NULL);
        else if (time.microseconds >= 1000000)
            sfClock_restart(txt_box->cursor_clock);
    }
}
