/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** txt_box_manage_text
*/

#include <txt_box.h>

static void txt_box_manage_click
    (sfRenderWindow *window, sfEvent event, txt_box_t *txt_box, void *w)
{
    sfVector2i pos_souris = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(txt_box->txt_box_s);

    if (event.type == sfEvtMouseButtonPressed) {
        if (pos_souris.x >= bounds.left
            && pos_souris.x <= bounds.left + bounds.width
            && pos_souris.y >= bounds.top
            && pos_souris.y <= bounds.top + bounds.height)
            txt_box->txt_box_hold = 1;
        else if (txt_box->size_map_function && txt_box->txt_box_hold) {
            txt_box->size_map_function(w);
            txt_box->txt_box_hold = 0;
        }
        else
            txt_box->txt_box_hold = 0;
    }
}

static int verify_txt(char c, txt_box_t *txt_box)
{
    if (txt_box->is_only_nb && (c < '0' || c > '9'))
        return (0);
    return (1);
}

static void txt_box_manage_text(sfEvent event, txt_box_t *text_box)
{
    if (event.type == sfEvtTextEntered && text_box->txt_box_hold) {
        if (event.text.unicode == 8 && text_box->nb_char > 0
            && event.text.unicode < 128
            && text_box->nb_char < text_box->limit_char + 1) {
            text_box->buffer[text_box->nb_char - 1] = '\0';
            text_box->nb_char -= 1;
            sfClock_restart(text_box->cursor_clock);
        }
        else if (event.text.unicode < 128
            && text_box->nb_char < text_box->limit_char
            && event.text.unicode != 8
            && verify_txt(event.text.unicode, text_box)) {
            text_box->buffer[text_box->nb_char] = event.text.unicode;
            text_box->buffer[text_box->nb_char + 1] = '\0';
            text_box->nb_char += 1;
            sfClock_restart(text_box->cursor_clock);
        }
    }
}

void txt_box_manage_event
    (sfRenderWindow *window, sfEvent event, txt_box_t *txt_box, void *w)
{
    txt_box_manage_click(window, event, txt_box, w);
    txt_box_manage_text(event, txt_box);
}
