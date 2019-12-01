/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** do the fonction to reverse a string
*/

#include <unistd.h>

int my_strlenn(char const *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    while (str[count] != '\0')
        count = count + 1;
    return (count);
}

char *my_revstr(char *str)
{
    int count = 0;
    int total = my_strlenn(str);
    int middle = total / 2;
    char c;

    total = total - 1;
    if (str == NULL)
        return (0);
    while (count < middle) {
        c = str[count];
        str[count] = str[total];
        str[total] = c;
        total = total - 1;
        count = count + 1;
    }
    return (str);
}
