/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** add new vertex to list
*/

#include "../../../include/paint.h"

void add_new_vertex_to_list(paint_t *paint)
{
    draw_t *new = malloc(sizeof(draw_t));
    paint->vertexList->index++;
    new->vertex_size = paint->draw->vertex_size;
    new->color = paint->draw->color;
    new->next = NULL;
    new->pos = sfMouse_getPosition((sfWindow *)paint->window);
    new->vertex = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(new->vertex, sfTriangleStrip);
    draw_t *tmp = paint->vertexList->draw;
    if (paint->vertexList->index == 0) {
        paint->vertexList->draw = new;
        return;
    }
    for (int i = 0; i < paint->vertexList->index - 1; i++) {
        tmp = tmp->next;
    }
    tmp->next = new;
}
