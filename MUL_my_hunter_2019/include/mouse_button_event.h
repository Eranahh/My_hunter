/*
** EPITECH PROJECT, 2019
** mouse_button_event
** File description:
** mouse_button_event
*/

#ifndef MOUSE_BUTTON_EVENT_H
#define MOUSE_BUTTON_EVENT_H

typedef struct game_s game_t;

typedef struct background_s background_t;

typedef struct mouse_button_event_s
{
    sfSprite *sp_mouse;
    sfTexture *tex_mouse;
    sfClock *m_clock;
    sfTime m_time;
    sfVector2i m_pos;
    sfIntRect m_rect;
    int check;
}mouse_t;

void mouse_click(game_t game, sprite_t *spr, background_t *bg, text_t *text);
void mouse_cursor(mouse_t *mouse, game_t game);
mouse_t display_mouse(sfRenderWindow *window, mouse_t mouse);


#endif
