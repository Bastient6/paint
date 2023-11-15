/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_drawing
*/

#include "../../include/paint.h"

void init_draw(paint_t *paint)
{
    paint->is_drawing = 0;
    paint->draw = malloc(sizeof(draw_t));
    paint->draw->vertex_size = 1;
    init_vectrice(paint);
}
