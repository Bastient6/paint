/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_rect
*/

#include "../../include/paint.h"

sfRectangleShape *init_rect_outline
    (paint_t *paint, sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape *rect = malloc(sizeof(sfRectangleShape *));
    rect = malloc(sizeof(sfRectangleShape *));
    rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRenderWindow_drawRectangleShape(paint->window, rect, NULL);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 1);
    return rect;
}
