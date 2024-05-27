/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** reset_view
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void reset_view_temp(data_t *data)
{
    sfView_setCenter(data->window->gameview, data->player->pos);
    sfView_setSize(data->window->gameview, (sfVector2f){WIDTH, HEIGHT});
    sfView_zoom(data->window->gameview, 0.6);
    data->window->view_pos = sfView_getCenter(data->window->gameview);
    sfRenderWindow_setView(data->window->window, data->window->gameview);
    sfView_setSize(data->window->view, (sfVector2f){WIDTH, HEIGHT});
    if (data->scene == SETTINGS || data->scene == MENU)
        sfView_zoom(data->window->view, 1);
    else
        sfView_zoom(data->window->view, 0.6);
    sfView_setCenter(data->window->view, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    data->window->view_pos = sfView_getCenter(data->window->view);
    sfRenderWindow_setView(data->window->window, data->window->view);
}
