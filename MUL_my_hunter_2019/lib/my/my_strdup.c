/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** do the fonction as same as strdup system
*/

#include <stdlib.h>
#include <unistd.h>

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return (dest);
}
