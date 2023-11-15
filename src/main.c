/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** main
*/

#include "../include/paint.h"

int main(void)
{
    paint_t *paint = malloc(sizeof(paint_t));
    get_save_file(paint);
    paint->color = sfBlack;
    open_window(paint);
    init_drop_down_button(paint);
    rec_color(paint);
    app_main_loop(paint);
    return 0;
}
