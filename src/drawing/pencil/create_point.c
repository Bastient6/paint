/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** create_point
*/

#include "../../../include/paint.h"

void create_point_y_valut(sfVertex *point, draw_t *draw)
{
    point->position.x =
            draw->prev_mouse_pos.x + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x = draw->pos.x - draw->vertex_size;
    point->position.y = draw->pos.y + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x = draw->pos.x + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x = draw->pos.x - draw->vertex_size;
    point->position.y = draw->pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x = draw->pos.x + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.y = draw->pos.y + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
}

void create_point_x_value(draw_t *draw, sfVertex *point)
{
    point->position.x = draw->pos.x - draw->vertex_size;
    point->position.y = draw->pos.y + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x = draw->pos.x + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);

    point->position.y = draw->pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x =
            draw->prev_mouse_pos.x + draw->vertex_size;
    point->position.y =
            draw->prev_mouse_pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);

    point->position.x =
            draw->prev_mouse_pos.x - draw->vertex_size;
    point->position.y =
            draw->prev_mouse_pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
}

void affine_point(draw_t *draw, sfVertex *point)
{
    point->position.x =
            draw->prev_mouse_pos.x + draw->vertex_size;
    point->position.y =
            draw->prev_mouse_pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.y =
            draw->prev_mouse_pos.y + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x = draw->pos.x + draw->vertex_size;
    point->position.y = draw->pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x = draw->pos.x - draw->vertex_size;
    point->position.y = draw->pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
}

void affine_point_x(draw_t * draw, sfVertex *point)
{
    point->position.x = draw->pos.x - draw->vertex_size;
    point->position.y = draw->pos.y + draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
    point->position.x =
            draw->prev_mouse_pos .x - draw->vertex_size;
    point->position.y =
            draw->prev_mouse_pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, *point);
}

void create_point(paint_t *paint, draw_t *draw)
{
    draw->prev_mouse_pos = draw->pos;
    draw->pos = sfMouse_getPosition((sfWindow *)paint->window);
    sfVertex point;
    point.color = paint->draw->color;
    point.position.x = draw->prev_mouse_pos.x - draw->vertex_size;
    point.position.y = draw->prev_mouse_pos.y - draw->vertex_size;
    sfVertexArray_append(draw->vertex, point);
    point.position.y = draw->prev_mouse_pos.y + paint->draw->vertex_size;
    sfVertexArray_append(draw->vertex, point);
    create_point_x_value(draw, &point);
    create_point_y_valut(&point, draw);
    affine_point(draw, &point);
    affine_point_x(draw, &point);
}
