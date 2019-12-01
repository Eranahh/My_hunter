/*
** EPITECH PROJECT, 2019
** open_windiow
** File description:
** open_windiow
*/

#include "my.h"

game_t display_window(game_t game)
{
    game.n = 0;
    game.mode.width = 1280;
    game.mode.height = 769;
    game.mode.bitsPerPixel = 32;
    game.window = sfRenderWindow_create(game.mode, "my_window", sfResize |
        sfClose, NULL);
    return (game);
}

void sprite_move(game_t game, sprite_t *spr, mouse_t *mouse, background_t *bg)
{
    clock_work(spr, game, bg);
    move_sprite(spr);
    mouse_cursor(mouse, game);
}

void choose_state(background_t bg, game_t game, sprite_t spr, mouse_t m)
{
    text_t text;

    text = text_data(text);
    text = score_display(text);
    while (sfRenderWindow_isOpen(game.window)) {
        my_event(game, &spr, &bg, &text);
        sfRenderWindow_clear(game.window, sfBlack);
        sfRenderWindow_drawSprite(game.window, bg.bg_sprite, NULL);
        background_rectangle(game, &bg);
        sprite_move(game, &spr, &m, &bg);
        sfRenderWindow_drawText(game.window, text.score, NULL);
        sfRenderWindow_drawText(game.window, text.t_score, NULL);
        sfRenderWindow_display(game.window);
    }
    destroy_other(text);
}

void lauch_game(background_t bg, game_t game, sprite_t spr, music_t play)
{
    mouse_t mouse;

    mouse.m_clock = sfClock_create();
    game.sp_clock = sfClock_create();
    bg.bg_clock = sfClock_create();
    game.clock = sfClock_create();
    game = display_window(game);
    play = music_play(play);
    sfRenderWindow_setFramerateLimit(game.window, 60);
    bg = display_background(game, bg);
    spr = display_sprite(game.window);
    mouse = display_mouse(game.window, mouse);
    choose_state(bg, game, spr, mouse);
    destroy_game(game, spr, bg, play);
}
