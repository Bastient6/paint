/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** pipette
*/

#include "../../../include/paint.h"

void pipette(paint_t *paint)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(paint->window);
    sfVector2f pos = {mouse.x, mouse.y};
    sfImage *image = sfRenderWindow_capture(paint->window);
    sfColor color = sfImage_getPixel(image, mouse.x, mouse.y);
    paint->color = color;
    sfRectangleShape_setPosition(paint->recmousse, pos);
    sfRectangleShape_setFillColor(paint->recmousse, color);
    sfRenderWindow_drawRectangleShape(paint->window, paint->recmousse, NULL);
}