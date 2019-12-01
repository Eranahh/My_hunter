/*
** EPITECH PROJECT, 2019
** background
** File description:
** draw the in game background
*/

#include "my.h"

background_t bg_data(background_t bg)
{
    bg.gl = 0;
    bg.turn = 10;
    bg.rect.top = 0;
    bg.rect.left = 3840;
    bg.rect.width = 1280;
    bg.rect.height = 769;
    return (bg);
}

void bg_check_rect(background_t *bg)
{
    if (bg->rect.left >= 6400)
        bg->check = 1;
    else if (bg->rect.left <= 0) {
        bg->check = 0;
    }
}

void background_rectangle(game_t game, background_t *bg)
{
    bg->bg_time = sfClock_getElapsedTime(bg->bg_clock);
    if (bg->turn == 7)
        bg->rect.left = 5200;
    else if (bg->turn > 5 && bg->turn < 7)
        bg->rect.left = 3840;
    if (bg->bg_time.microseconds > (200000 * bg->gl) && bg->gl == 1) {
        bg_check_rect(bg);
        if (bg->check == 0)
            bg->rect.left += 1280;
        else
            bg->rect.left = 0;
        sfClock_restart(bg->bg_clock);
    }
    sfSprite_setTextureRect(bg->bg_sprite, bg->rect);
    sfRenderWindow_drawSprite(game.window, bg->bg_sprite, NULL);
}

background_t display_background(game_t game, background_t bg)
{
    bg.check = 0;
    bg = bg_data(bg);
    bg.bg_texture = sfTexture_createFromFile("assets/map_glitched.png",
        NULL);
    bg.bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg.bg_sprite, bg.bg_texture, 0);
    sfRenderWindow_drawSprite(game.window, bg.bg_sprite, NULL);
    return (bg);
}
