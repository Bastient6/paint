/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** display_save_file
*/

#include "../../include/paint.h"

void display_save_file(paint_t *paint)
{
    int i = 0;
    struct dirent *files = NULL;
    DIR *directory;
    directory = opendir("./src/save_file");
    if (directory == NULL)
        return;
    for (;files = readdir(directory) != NULL; i++){
        sfText *text = sfText_create();
        sfText_setString(text, files->d_name);
        paint->font = sfFont_createFromFile("src/sprite/OpenSans-Light.ttf");
        sfText_setFont(text, paint->font);
        sfText_setCharacterSize(text, 30);
        sfText_setPosition(text, (sfVector2f){100, 100 + i * 50});
        sfText_setColor(text, sfBlack);
        sfRenderWindow_drawText(paint->window, text, NULL);
    }
}
