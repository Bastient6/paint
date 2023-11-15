/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_sprite
*/

#include "../../include/paint.h"

void init_sprite_pinceau(paint_t *paint)
{
    paint->pinceau = sfSprite_create();
    paint->pinceautexture =
            sfTexture_createFromFile("./src/sprite/pinceau.png", NULL);
    sfSprite_setTexture(paint->pinceau, paint->pinceautexture, sfTrue);
    sfSprite_setPosition(paint->pinceau, (sfVector2f){20, 300});
    sfSprite_setScale(paint->pinceau, (sfVector2f){0.1, 0.1});
    sfRenderWindow_drawSprite(paint->window, paint->pinceau, NULL);
}
