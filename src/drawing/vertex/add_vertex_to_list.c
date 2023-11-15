/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** add_vertex_to_list
*/

#include "../../../include/paint.h"

void add_vertex_to_list(paint_t *paint)
{
    static int i = 0;

    if (paint->is_drawing == 1) {
        paint->draw->color = paint->color;
        draw_t *tmp = paint->vertexList->draw;
        if (paint->vertexList->index == 0) {
            create_point(paint, tmp);
            return;
        }
        for (int i = 0; i < paint->vertexList->index ; i++) {
            tmp = tmp->next;
        }
        create_point(paint, tmp);
    }
}
