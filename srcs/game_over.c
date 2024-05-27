/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** game_over
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void display_go(data_t *data)
{
    sfRenderWindow_clear(data->window->window, sfBlack);
    manage_events(data);
    sfRenderWindow_display(data->window->window);
}
