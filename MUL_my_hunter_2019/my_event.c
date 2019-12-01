/*
** EPITECH PROJECT, 2019
** my_event
** File description:
** my_event
*/

#include "my.h"

game_t death_animation(sprite_t *spr, game_t game)
{
    game.sp_time = sfClock_getElapsedTime(game.sp_clock);
    if (game.sp_time.microseconds > 100000) {
        check_death_rect(spr);
        if (spr->d_check == 0)
            spr->death_rect.left += 110;
        else {
            spr->death_rect.left -= 110;
            game.n = 1;
        }
        sfClock_restart(game.sp_clock);
    }
    sfSprite_setTextureRect(spr->sp_death, spr->death_rect);
    sfRenderWindow_drawSprite(game.window, spr->sp_death, NULL);
    sfSprite_setPosition(spr->sp_death, spr->d_pos);
    return (game);
}

int calculation(sfVector2i pos, sprite_t spr)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(spr.sprite);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue)
        return (1);
    return (0);
}

void collision(game_t game, sprite_t *spr, background_t *bg, text_t *text)
{
    sfVector2i res = sfMouse_getPositionRenderWindow(game.window);

    if (calculation(res, *spr) == 1) {
        spr->d_pos.x = spr->pos.x;
        spr->d_pos.y = spr->pos.y;
        game = death_animation(spr, game);
        spr->pos.x = -200;
        spr->pos.y = rand() % 525;
        sfSprite_setPosition(spr->sprite, spr->pos);
        bg->turn -= 0.5;
        text->nb++;
        score_update(text);
        sfRenderWindow_drawText(game.window, text->t_score, NULL);
        if (bg->turn <= 5) {
            spr->change = 1;
            spr->hit = 1;
            bg->gl = 1;
        }
    }
}

void mouse_click(game_t game, sprite_t *spr, background_t *bg, text_t *text)
{
    if (game.event.type == sfEvtMouseButtonPressed) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            collision(game, spr, bg, text);
        }
    }
}

void my_event(game_t gam, sprite_t *spr, background_t *bg, text_t *text)
{
    while (sfRenderWindow_pollEvent(gam.window, &gam.event)) {
        if (gam.event.type == sfEvtClosed || gam.event.key.code == sfKeyEscape)
            sfRenderWindow_close(gam.window);
        mouse_click(gam, spr, bg, text);
    }
}
