/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** zone
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void is_p_in_zone(data_t *data)
{
    if (data->player->isgm == sfTrue) {
        sfRenderWindow_drawRectangleShape(data->window->window,
        data->zones[0]->shape, NULL);
        sfRenderWindow_drawRectangleShape(data->window->window,
        data->zones[1]->shape, NULL);
    }
    for (int i = 0; i != NB_ZONES; i ++) {
        if (data->player->pos.x > data->zones[i]->pos.x &&
        data->player->pos.x < data->zones[i]->pos.x +
        data->zones[i]->size.x &&
        data->player->pos.y > data->zones[i]->pos.y &&
        data->player->pos.y < data->zones[i]->pos.y +
        data->zones[i]->size.y) {
            data->current_zone = data->zones[i];
            return;
        }
    }
    data->current_zone = NULL;
}
