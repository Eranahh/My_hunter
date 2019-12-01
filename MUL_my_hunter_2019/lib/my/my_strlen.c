/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** do a fonction that counts the numbers of charac
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    while (str[count] != '\0')
        count++;
    return (count);
}
