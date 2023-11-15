/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_vertex
*/

#include"../../../include/paint.h"

void init_vectrice(paint_t *paint)
{
    paint->draw->vertex = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(paint->draw->vertex, sfTriangleStrip);
}
