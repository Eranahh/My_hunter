/*
** EPITECH PROJECT, 2019
** clock_function
** File description:
** clock_function
*/

#include "my.h"

void check_death_rect(sprite_t *spr)
{
    if (spr->death_rect.left >= 440)
        spr->d_check = 1;
    else if (spr->death_rect.left <= 0)
        spr->d_check = 0;
}

void check_rect(sprite_t *spr)
{
    if (spr->rect.left >= 880)
        spr->check = 1;
    else if (spr->rect.left <= 330)
        spr->check = 0;
}

void check_normal_rect(sprite_t *spr)
{
    if (spr->rect.left >= 220)
        spr->check = 1;
    else if (spr->rect.left <= 0)
        spr->check = 0;
}

void y_pos(game_t game, sprite_t *spr)
{
    if (game.time_f.microseconds > (10000 * spr->hit) && spr->hit == 1)
        spr->pos.y = rand() % 525;
    sfSprite_setPosition(spr->sprite, spr->pos);
}

void clock_work(sprite_t *spr, game_t game, background_t *bg)
{
    game.time_f = sfClock_getElapsedTime(game.clock);
    srand(time(0));
    if (bg->turn == 7) {
        spr->rect.left = 880;
        spr->pos.x = 430;
        spr->pos.y = 450;
    } else if (game.time_f.microseconds > 100000) {
        if (spr->change == 0)
            check_normal_rect(spr);
        else if (spr->change == 1)
            check_rect(spr);
        if (spr->check == 0)
            spr->rect.left += 110;
        else
            spr->rect.left -= 110;
        y_pos(game, spr);
        sfClock_restart(game.clock);
    }
    sfSprite_setTextureRect(spr->sprite, spr->rect);
    sfRenderWindow_drawSprite(game.window, spr->sprite, NULL);
}
