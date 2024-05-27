/*
** EPITECH PROJECT, 2024
** my_super_str_cat
** File description:
** str_cat but nanoboosted
*/

#include "../includes/rpg.h"

int set_temp_value(int value, int *len_value)
{
    int temp_value = value;

    while (temp_value / 10 != 0) {
        (*len_value)++;
        temp_value /= 10;
    }
    return temp_value;
}

char *my_super_str_cat_int(const char *string,
    int value, const char *extension)
{
    int len_string = my_strlen(string);
    int len_value = 1;
    int len_extension = my_strlen(extension);
    char *result;

    set_temp_value(value, &len_value);
    result = malloc(sizeof(char) *
    (len_string + len_value + len_extension + 1));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < len_string; i++)
        result[i] = string[i];
    for (int i = len_value - 1; i >= 0; i--) {
        result[len_string + i] = '0' + value % 10;
        value /= 10;
    }
    for (int i = 0; i < len_extension; i++)
        result[len_string + len_value + i] = extension[i];
    result[len_string + len_value + len_extension] = '\0';
    return result;
}
