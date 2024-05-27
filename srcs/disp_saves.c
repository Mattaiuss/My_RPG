/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** disp_saves
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void draw_saves(data_t *data)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->window->clock))
    > 1000 / 60) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        sfRenderWindow_drawSprite(data->window->window,
        data->menu->bg_sprite, NULL);
        sfRenderWindow_drawSprite(data->window->window,
        data->window->mouse->sprite, NULL);
        sfRenderWindow_display(data->window->window);
    }
}
