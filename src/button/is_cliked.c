/*
** EPITECH PROJECT, 2023
** bs_mypaint
** File description:
** is_cliked
*/

#include "../../include/paint.h"

sfBool is_clicked(button_t *button, sfMouseButtonEvent *mouseButton)
{
    sfFloatRect rectpos = sfRectangleShape_getGlobalBounds(button->rect);
    if (sfFloatRect_contains(&rectpos, mouseButton->x, mouseButton->y)
    && mouseButton->button == sfMouseLeft &&
    mouseButton->type == sfEvtMouseButtonPressed) {
        button->state = PRESSED;
        return sfTrue;
    }
    button->state = RELEASED;
    return sfFalse;
}
