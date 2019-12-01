/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include "include/my.h"

void destroy_menu(menu_t menu)
{
    sfSprite_destroy(menu.menu_spr);
    sfSprite_destroy(menu.but_play_spr);
    sfSprite_destroy(menu.but_quit_spr);
    sfTexture_destroy(menu.menu_tex);
    sfTexture_destroy(menu.but_play_tex);
    sfTexture_destroy(menu.but_quit_tex);
}

menu_t menu_data(sfRenderWindow *window, menu_t menu)
{
    menu.button_rect.top = 0;
    menu.button_rect.left = 0;
    menu.button_rect.width = 200;
    menu.button_rect.height = 70;
    menu.pos_play.x = 300;
    menu.pos_play.y = 340;
    menu.pos_quit.x = 300;
    menu.pos_quit.y = 540;
    menu.menu_tex = sfTexture_createFromFile("assets/menu.png", NULL);
    menu.menu_spr = sfSprite_create();
    sfSprite_setTexture(menu.menu_spr, menu.menu_tex, sfTrue);
    sfRenderWindow_drawSprite(window, menu.menu_spr, NULL);
    return (menu);
}

menu_t menu_button(sfRenderWindow *window, menu_t menu)
{
    menu.but_play_tex = sfTexture_createFromFile("assets/play.png", NULL);
    menu.but_quit_tex = sfTexture_createFromFile("assets/quit.png", NULL);
    menu.but_play_spr = sfSprite_create();
    menu.but_quit_spr = sfSprite_create();
    sfSprite_setTexture(menu.but_play_spr, menu.but_play_tex, sfTrue);
    sfSprite_setTexture(menu.but_quit_spr, menu.but_quit_tex, sfTrue);
    sfRenderWindow_drawSprite(window, menu.but_play_spr, NULL);
    sfRenderWindow_drawSprite(window, menu.but_quit_spr, NULL);
    sfSprite_setPosition(menu.but_play_spr, menu.pos_play);
    sfSprite_setPosition(menu.but_quit_spr, menu.pos_quit);
    return (menu);
}

void display_menu(sfRenderWindow *window)
{
    menu_t menu;

    menu = menu_data(window, menu);
    menu = menu_button(window, menu);
}
