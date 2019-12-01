/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** sprite data
*/

#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.h>
#include "game.h"

typedef struct background_s background_t;

typedef struct sprite_s
{
    sfTexture *texture;
    sfTexture *tex_death;
    sfSprite *sprite;
    sfSprite *sp_death;
    sfIntRect death_rect;
    sfIntRect rect;
    int change;
    int check;
    int d_check;
    int hit;
    int n;
    sfVector2f pos;
    sfVector2f d_pos;
}sprite_t;

sprite_t display_sprite(sfRenderWindow *window);
void move_sprite(sprite_t *spr);
void clock_work(sprite_t *spr, game_t game, background_t *bg);
void collision(game_t game, sprite_t *spr, background_t *bg, text_t *text);
void check_death_rect(sprite_t *spr);
game_t death_animation(sprite_t *spr, game_t game);

#endif
