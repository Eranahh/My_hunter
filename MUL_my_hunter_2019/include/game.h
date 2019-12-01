/*
** EPITECH PROJECT, 2019
** game_h
** File description:
** game_h
*/

#ifndef GAME_H
#define GAME_H

#include <time.h>

typedef struct sprite_s sprite_t;

typedef struct background_s background_t;

typedef struct text_s text_t;

typedef struct game_s
{
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfClock *sp_clock;
    sfTime time_f;
    sfTime sp_time;
    int n;
}game_t;

void my_event(game_t game, sprite_t *spr, background_t *bg, text_t *text);
void help(void);

#endif
