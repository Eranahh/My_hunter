/*
** EPITECH PROJECT, 2019
** music
** File description:
** music
*/

#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.h>

typedef struct music_s
{
    sfMusic *music;
}music_t;

music_t music_play(music_t play);

#endif
