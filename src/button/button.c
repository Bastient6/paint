/*
** EPITECH PROJECT, 2023
** bs_mypaint
** File description:
** button
*/

#include "../../include/paint.h"

void init_text(char * text, button_t *button, sfVector2f size, sfColor color)
{
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->size = size;
    button->color = color;
    button->text = sfText_create();
    button->font = sfFont_createFromFile("src/sprite/OpenSans-Light.ttf");
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, text);
    sfText_setCharacterSize(button->text, ((size.y / 2) + (size.x / 2)) / 2);
    sfText_setColor(button->text, sfWhite);
}

button_t *init_button
(sfVector2f position, sfVector2f size, sfColor color, char *text)
{
    button_t *button = malloc (sizeof (button_t));
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor (button->rect, color);
    button->text = sfText_create();
    sfText_setString(button->text, text);
    button->font = sfFont_createFromFile("src/sprite/OpenSans-Light.ttf");
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 50);
    sfText_setColor(button->text, sfWhite);
    sfText_setPosition(button->text,
    (sfVector2f){position.x + 10, position.y + 10});
    button->position = position;
    init_text(text, button, size, color);
    sfFloatRect size_text = sfText_getGlobalBounds(button->text);
    sfText_setPosition(button->text,
    (sfVector2f){position.x + ((size.x - size_text.width) / 2),
    position.y + ((size.y - size_text.height) / size.y )});
    return button;
}
