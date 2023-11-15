/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** get_save_file
*/

#include "../../include/paint.h"

void get_save_file(paint_t *paint)
{
    int i = 0;
    struct dirent *files = NULL;
    DIR *directory;
    directory = opendir("./src/save_file");
    if (directory == NULL){
        paint->i = '.';
        return;
    }
    for (;(files = readdir(directory)) != NULL; i++);
    paint->i = i + '.';
}
