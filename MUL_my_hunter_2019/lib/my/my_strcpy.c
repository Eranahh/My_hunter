/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** do a fonction that copy a string
*/

#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;

    if (src == NULL)
        return (NULL);
    while (src[count] != '\0') {
        dest[count] = src[count];
        count++;
    }
    dest[count] = '\0';
    return (dest);
}
