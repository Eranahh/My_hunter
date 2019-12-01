/*
** EPITECH PROJECT, 2019
** menu_h
** File description:
** menu_h
*/

#ifndef MENU_H
#define MENU_H

typedef struct menu_s
{
    sfSprite *menu_spr;
    sfTexture *menu_tex;
    sfSprite *but_play_spr;
    sfTexture *but_play_tex;
    sfSprite *but_quit_spr;
    sfTexture *but_quit_tex;
    sfIntRect button_rect;
    sfVector2f pos_play;
    sfVector2f pos_quit;
}menu_t;

void display_menu(sfRenderWindow *window);
void destroy_menu(menu_t menu);

#endif
