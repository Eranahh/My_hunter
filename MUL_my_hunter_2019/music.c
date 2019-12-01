/*
** EPITECH PROJECT, 2019
** music_lauch
** File description:
** music_lauch
*/

#include "my.h"

music_t music_play(music_t play)
{
    play.music = sfMusic_createFromFile("music/touhou.ogg");
    sfMusic_play(play.music);
    sfMusic_setLoop(play.music, sfTrue);
    return (play);
}
