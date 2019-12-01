/*
** EPITECH PROJECT, 2019
** background
** File description:
** background
*/

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.h>

typedef struct background_s
{
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfIntRect rect;
    sfClock *bg_clock;
    sfTime bg_time;
    int check;
    float turn;
    float gl;
}background_t;

void background_rectangle(game_t game, background_t *bg);
background_t display_background(game_t game, background_t bg);

#endif
