/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** save_function
*/

#include "../../include/paint.h"

void save_function(paint_t *paint)
{
    if (paint->i <= '9'){
        char *arg = malloc(sizeof(char) * 100);
        arg[0] = '\0';
        arg = str_concat(arg, "./src/save_file/save .jpg");
        sfImage *image = sfRenderWindow_capture(paint->window);
        sfImage *copimage = sfImage_create(1640, 1010);
        sfIntRect rect = {200, 20, 1920,1080};
        sfImage_copyImage(copimage, image, 0,0, rect, sfTrue);
        arg = str_concat_with_number(arg, paint->i);
        sfImage_saveToFile(copimage, arg);
        paint->i++;
    }
}
