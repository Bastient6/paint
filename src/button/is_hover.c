/*
** EPITECH PROJECT, 2023
** bs_mypaint
** File description:
** is_hover
*/

#include "../../include/paint.h"

sfBool is_hover(button_t *button, sfMouseMoveEvent *mouseMove, sfWindow *window)
{
    sfFloatRect rectpos = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)window);
    if (sfFloatRect_contains(&rectpos, mouse_pos.x, mouse_pos.y)) {
        button->state = HOVER;
        return sfTrue;
    }
    button->state = RELEASED;
    return sfFalse;
}
