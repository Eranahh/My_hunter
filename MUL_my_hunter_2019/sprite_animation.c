/*
** EPITECH PROJECT, 2019
** sprite_animation
** File description:
** sprite_animation
*/

#include "my.h"

sprite_t sprite_data(sprite_t spr)
{
    spr.change = 0;
    spr.n = 0;
    spr.hit = 0;
    spr.pos.x = -200;
    spr.pos.y = 0;
    spr.d_pos.x = 0;
    spr.d_pos.y = 0;
    spr.rect.top = 0;
    spr.rect.left = 0;
    spr.rect.width = 110;
    spr.rect.height = 110;
    spr.death_rect.top = 0;
    spr.death_rect.left = 0;
    spr.death_rect.width = 110;
    spr.death_rect.height = 110;
    return (spr);
}

void move_sprite(sprite_t *spr)
{
    spr->pos.x += 10;
    if (spr->pos.x == 1400)
        spr->pos.x = -200;
    sfSprite_setPosition(spr->sprite, spr->pos);
}

sprite_t display_sprite(sfRenderWindow *window)
{
    sprite_t spr;

    spr.check = 0;
    spr.d_check = 0;
    spr = sprite_data(spr);
    spr.sp_death = sfSprite_create();
    spr.sprite = sfSprite_create();
    spr.tex_death = sfTexture_createFromFile("assets/death_anim.png", NULL);
    spr.texture = sfTexture_createFromFile("assets/comb_duck.png", NULL);
    sfSprite_setTexture(spr.sp_death, spr.tex_death, sfTrue);
    sfSprite_setTexture(spr.sprite, spr.texture, sfTrue);
    sfRenderWindow_drawSprite(window, spr.sp_death, NULL);
    sfRenderWindow_drawSprite(window, spr.sprite, NULL);
    sfSprite_setPosition(spr.sp_death, spr.d_pos);
    sfSprite_setPosition(spr.sprite, spr.pos);
    return (spr);
}
