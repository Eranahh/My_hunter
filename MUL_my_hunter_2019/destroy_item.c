/*
** EPITECH PROJECT, 2019
** destroy_item
** File description:
** destroy_item
*/

#include "my.h"

void destroy_game(game_t game, sprite_t spr, background_t bg, music_t play)
{
    sfMusic_destroy(play.music);
    sfSprite_destroy(bg.bg_sprite);
    sfTexture_destroy(bg.bg_texture);
    sfSprite_destroy(spr.sprite);
    sfTexture_destroy(spr.texture);
    sfRenderWindow_destroy(game.window);
}

void destroy_other(text_t text)
{
    sfText_destroy(text.score);
}
