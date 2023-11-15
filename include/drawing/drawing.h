/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** drawing.h
*/

#ifndef DRAWING_H_
    #define DRAWING_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

    #define BUFFER 1000

    typedef struct draw_s{
        sfVertexArray *vertex;
        sfVertex point;
        int vertex_size;
        sfColor color;
        sfVector2i pos;
        sfVector2i prev_mouse_pos;
        struct draw_s *next;
    }draw_t;

    typedef struct vertex_list_s{
        int index;
        draw_t *draw;
    }vertex_list_t;

#endif /*DRAWING_H_*/
