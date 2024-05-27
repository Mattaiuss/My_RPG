/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** int_to_str
*/

#include <stdlib.h>

void check_negatif(int *nb, char **str, int mode, int *size)
{
    if (*nb < 0) {
        *nb *= -1;
        if (mode == 1) {
            *str[*size] = '-';
            *size = 1;
        }
    }
}

char *int_to_str(int nb, int mode)
{
    int i = 0;
    int size = 0;
    char *str = malloc(sizeof(char) * 12);

    check_negatif(&nb, &str, mode, &size);
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    for (int tmp = nb; tmp > 0; tmp /= 10)
        size++;
    str[size] = '\0';
    for (int tmp = nb; tmp > 0; tmp /= 10) {
        str[size - i - 1] = tmp % 10 + '0';
        i++;
    }
    return (str);
}
