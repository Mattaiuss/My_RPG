/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** events
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void check_effect_clock(data_t *data)
{
    sfTime time = {0};

    if (data->player->effect_clock != NULL && data->scene == GAME) {
        time = sfClock_getElapsedTime(data->player->effect_clock);
        if (sfTime_asSeconds(time) >= 10.0f) {
            data->player->speed = 2;
            sfClock_destroy(data->player->effect_clock);
            data->player->effect_clock = NULL;
        }
    }
}

void manage_resize(data_t *data)
{
    data->mouse_pos = sfMouse_getPositionRenderWindow(data->window->window);
    data->window->mouse_pos = (sfVector2f){data->mouse_pos.x,
        data->mouse_pos.y};
}

void manage_events(data_t *data)
{
    while (sfRenderWindow_pollEvent(data->window->window,
    &data->window->event)) {
        manage_resize(data);
        if (data->window->event.type == sfEvtClosed)
            data->scene = -1;
        if (data->window->event.type == sfEvtKeyPressed)
            check_key_pressed(data);
        if (data->window->event.type == sfEvtKeyReleased)
            check_key_released(data);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft)
            data->keys->left_click = sfFalse;
        if (data->window->event.type == sfEvtMouseButtonPressed &&
            data->window->event.mouseButton.button == sfMouseLeft)
            data->keys->left_click = sfTrue;
    }
}
