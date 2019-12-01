/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    music_t play;
    game_t game;
    sprite_t spr;
    background_t bg;

    if (ac != 1 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        help();
        return (1);
    }
    else if (ac == 1)
        lauch_game(bg, game, spr, play);
    else
        return (84);
    return (0);
}
