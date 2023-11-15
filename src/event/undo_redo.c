/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_vertex
*/

#include"../../include/paint.h"

void undo_function(paint_t *paint)
{
    if (paint->vertexList->index > -1) {
        paint->vertexList->index--;
    }
}

void redo_function(paint_t *paint)
{
    draw_t *tmp = paint->vertexList->draw;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    if (paint->vertexList->index < count - 1) {
        paint->vertexList->index++;
    }
}
