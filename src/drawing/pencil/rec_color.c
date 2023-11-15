/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** rec_color
*/

#include "../../../include/paint.h"

void rec_color(paint_t *paint)
{
    paint->recmousse = sfRectangleShape_create();
    sfVector2f size = (sfVector2f){paint->draw->vertex_size, paint->draw->vertex_size};
    sfVector2f pos2 = {500, 500};
    sfColor color = sfTransparent;
    sfRectangleShape_setSize(paint->recmousse, size);
    sfRectangleShape_setPosition(paint->recmousse, pos2);
    sfRectangleShape_setFillColor(paint->recmousse, sfTransparent);
    sfRectangleShape_setOutlineColor(paint->recmousse, paint->color);
    sfRectangleShape_setOutlineThickness(paint->recmousse, 2);
    sfRenderWindow_drawRectangleShape(paint->window, paint->recmousse, NULL);
}