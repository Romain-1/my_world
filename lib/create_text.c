/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** create_text
*/

#include <txt_box.h>

sfText *create_text(sfColor color, unsigned int taille,
                    sfVector2f position, char const *contenue)
{
    sfFont *font = sfFont_createFromFile("resources/arial.ttf");
    sfText *text = sfText_create();

    sfText_setCharacterSize(text, taille);
    sfText_setPosition(text, position);
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setString(text, contenue);
    return (text);
}
