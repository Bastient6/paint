/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** add_file_button
*/

#include "../../include/paint.h"

void file_drop_button(paint_t *paint)
{
    paint->drop_file_button = create_drop_menu
            ((sfVector2f){5, 0}, (sfVector2f){60, 30}, DARK_GREY, "File");
    paint->drop_file_button = add_option_drop_menu
            (paint->drop_file_button, "New", 1);
    paint->drop_file_button = add_option_drop_menu
            (paint->drop_file_button, "Open", 2);
    paint->drop_file_button = add_option_drop_menu
            (paint->drop_file_button, "Save", 3);
}

void edit_drop_button(paint_t * paint)
{
    paint->drop_edit_button = create_drop_menu
            ((sfVector2f){70, 0}, (sfVector2f){60, 30}, DARK_GREY, "Edit");
    paint->drop_edit_button = add_option_drop_menu
            (paint->drop_edit_button, "Undo", 4);
    paint->drop_edit_button = add_option_drop_menu
            (paint->drop_edit_button, "Redo", 5);
    paint->drop_edit_button = add_option_drop_menu
            (paint->drop_edit_button, "Clear",6);
}

void init_drop_help_button(paint_t *paint)
{
    paint->drop_help_button = create_drop_menu
            ((sfVector2f){135, 0}, (sfVector2f){60, 30}, DARK_GREY, "Help");
    paint->drop_help_button = add_option_drop_menu
            (paint->drop_help_button, "About", 7);
    paint->drop_help_button = add_option_drop_menu
            (paint->drop_help_button, "Help", 8);
}

void init_drop_down_button(paint_t *paint)
{
    file_drop_button(paint);
    edit_drop_button(paint);
    init_drop_help_button(paint);
    paint->drop_open_button = create_drop_menu
            ((sfVector2f){65, 60}, (sfVector2f){80, 30}, DARK_GREY, "Files");
}
