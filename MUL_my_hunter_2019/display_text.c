/*
** EPITECH PROJECT, 2019
** display_text
** File description:
** display_text
*/

#include "my.h"

text_t text_data(text_t text)
{
    text.nb = 0;
    text.pos.x = 1000;
    text.pos.y = 700;
    text.t_pos.x = 1160;
    text.t_pos.y = 700;
    text.font = sfFont_createFromFile("font/ARCADECLASSIC.TTF");
    text.t_font = sfFont_createFromFile("font/ARCADECLASSIC.TTF");
    text.score = sfText_create();
    text.t_score = sfText_create();
    return (text);
}

text_t score_display(text_t text)
{
    sfText_setString(text.score, " Score ");
    sfText_setString(text.t_score, "0");
    sfText_setFont(text.score, text.font);
    sfText_setFont(text.t_score, text.t_font);
    sfText_setCharacterSize(text.score, 50);
    sfText_setCharacterSize(text.t_score, 50);
    sfText_setPosition(text.score, text.pos);
    sfText_setPosition(text.t_score, text.t_pos);
    return (text);
}

void score_update(text_t *text)
{
    char *res = malloc(sizeof(char) * 3);

    res[0] = text->nb + 48;
    res[1] = 0;
    res[2] = '\0';
    sfText_setFont(text->t_score, text->t_font);
    if (text->nb > 9) {
        if (text->nb % 5 == 0)
            res = my_strcpy(res, "%*&");
        if (text->nb % 5 == 1)
            res = my_strcpy(res, "UwU");
        if (text->nb % 5 == 2)
            res = my_strcpy(res, "o@f");
        if (text->nb % 5 == 3)
            res = my_strcpy(res, "4/£");
        if (text->nb % 5 == 4)
            res = my_strcpy(res, "-21");
        text->t_font = sfFont_createFromFile("font/Arial.ttf");
    }
    sfText_setString(text->t_score, res);
}
