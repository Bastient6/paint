/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_sprite_pipette
*/

#include "../../include/paint.h"

void init_sprite_pipette(paint_t *paint)
{
    paint->pipette = sfSprite_create();
    paint->pipettetexture = sfTexture_createFromFile("./src/sprite/pipette.ng", NULL);
    sfSprite_setTexture(paint->pipette, paint->pipettetexture, sfTrue);
    sfSprite_setPosition(paint->pipette, (sfVector2f){0, 0});
    sfSprite_setScale(paint->pipette, (sfVector2f){0.1, 0.1});
}