/*
** EPITECH PROJECT, 2019
** text
** File description:
** text
*/

#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.h>
#include <stddef.h>

typedef struct text_s
{
    sfText *score;
    sfFont *font;
    sfText *t_score;
    sfFont *t_font;
    int nb;
    sfVector2f pos;
    sfVector2f t_pos;
}text_t;

text_t text_data(text_t text);
text_t score_display(text_t text);
void score_update(text_t *text);

#endif
