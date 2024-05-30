/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** manage_line
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

char *allocate_text(char *str, char *text)
{
    char *result = malloc(strlen(str) + strlen(text) + 1);

    strcpy(result, str);
    strcat(result, text);
    return result;
}

int find_last_space_within_width(sfText *text, char *str, float width)
{
    int index = strlen(str) - 1;
    char *substring = NULL;
    sfFloatRect textRect;

    while (index >= 0) {
        substring = malloc(index + 2);
        strncpy(substring, str, index + 1);
        substring[index + 1] = '\0';
        sfText_setString(text, substring);
        textRect = sfText_getLocalBounds(text);
        free(substring);
        if (textRect.width <= width && str[index] == ' ') {
            return index;
        }
        index--;
    }
    return -1;
}

char *add_newline_if_needed(sfText *text, sfSprite *sprite, char *str, int rec)
{
    sfFloatRect textRect;
    sfFloatRect spriteRect;
    int lastSpace = -2;

    sfText_setString(text, str);
    textRect = sfText_getLocalBounds(text);
    spriteRect = sfSprite_getGlobalBounds(sprite);
    spriteRect.width -= rec;
    while (textRect.width > spriteRect.width) {
        lastSpace = find_last_space_within_width(text, str, spriteRect.width);
        if (lastSpace == -1) {
            lastSpace = spriteRect.width;
        }
        str[lastSpace] = '\n';
        sfText_setString(text, str);
        textRect = sfText_getLocalBounds(text);
    }
    return str;
}

int count_newlines(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            count++;
        }
    }
    return count;
}
