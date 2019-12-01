/*
** EPITECH PROJECT, 2019
** mouse_function
** File description:
** mouse_function
*/

#include "my.h"

mouse_t sprite_mouse_data(mouse_t mouse)
{
    mouse.m_pos.x = 0;
    mouse.m_pos.y = 0;
    mouse.m_rect.top = 0;
    mouse.m_rect.left = 0;
    mouse.m_rect.width = 60;
    mouse.m_rect.height = 60;
    return (mouse);
}

mouse_t display_mouse(sfRenderWindow *window, mouse_t mouse)
{
    mouse.check = 0;
    mouse = sprite_mouse_data(mouse);
    mouse.sp_mouse = sfSprite_create();
    mouse.tex_mouse = sfTexture_createFromFile("assets/cursor(2).png", NULL);
    sfSprite_setTexture(mouse.sp_mouse, mouse.tex_mouse, sfTrue);
    sfRenderWindow_drawSprite(window, mouse.sp_mouse, NULL);
    return (mouse);
}

void check_mouse_rect(mouse_t *mouse)
{
    if (mouse->m_rect.left >= 120)
        mouse->check = 1;
    else if (mouse->m_rect.left <= 0)
        mouse->check = 0;
}

void mouse_cursor(mouse_t *mouse, game_t game)
{
    sfVector2f res;

    mouse->m_pos = sfMouse_getPositionRenderWindow(game.window);
    res.x = mouse->m_pos.x;
    res.y = mouse->m_pos.y;
    mouse->m_time = sfClock_getElapsedTime(mouse->m_clock);
    srand(time(0));
    if (mouse->m_time.microseconds > 100000) {
        check_mouse_rect(mouse);
        if (mouse->check == 0)
            mouse->m_rect.left += 60;
        else
            mouse->m_rect.left -= 60;
        sfClock_restart(mouse->m_clock);
    }
    sfSprite_setTextureRect(mouse->sp_mouse, mouse->m_rect);
    sfRenderWindow_drawSprite(game.window, mouse->sp_mouse, NULL);
    sfSprite_setPosition(mouse->sp_mouse, res);
}
