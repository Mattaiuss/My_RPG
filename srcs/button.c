/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** button
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

sfBool is_hover(button_t *button, data_t *data)
{
    sfFloatRect sprite = sfSprite_getGlobalBounds(button->sprite);
    float x = data->window->mouse_pos.x;
    float y = data->window->mouse_pos.y;

    if (x >= sprite.left && x <= sprite.left + sprite.width &&
    y >= sprite.top && y <= sprite.top + sprite.height) {
        return (sfTrue);
    }
    return (sfFalse);
}
