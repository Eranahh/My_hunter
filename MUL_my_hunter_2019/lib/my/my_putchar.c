/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** do the fonction to write only one character
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
