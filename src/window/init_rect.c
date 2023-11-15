/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_rect
*/

#include "../../include/paint.h"

sfRectangleShape *init_rect
(paint_t *paint, sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape *rect;
    rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRenderWindow_drawRectangleShape(paint->window, rect, NULL);
    return rect;
}
