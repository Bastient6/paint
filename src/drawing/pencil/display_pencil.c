/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** display_pencil
*/

#include "../../../include/paint.h"

void display_pencil(paint_t *paint)
{
    draw_t *tmp = paint->vertexList->draw;
    for (int i = 0; i < paint->vertexList->index + 1; i++) {
        sfRenderWindow_drawVertexArray(paint->window, tmp->vertex, NULL);
        tmp = tmp->next;
    }
}
