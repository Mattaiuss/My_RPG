/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** events_keys
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void check_fullscreen_key(data_t *data)
{
    if (data->window->event.key.code == sfKeyF11 &&
    data->keys->is_fullscreen_pressed == sfFalse) {
        data->keys->is_fullscreen_pressed = sfTrue;
        data->window->is_fullscreen = sfTrue;
        sfRenderWindow_close(data->window->window);
        data->window->mode = (sfVideoMode){1920, 1080, 32};
        data->window->window = sfRenderWindow_create(data->window->mode,
        "My_RPG", sfFullscreen, NULL);
    } else if (data->window->event.key.code == sfKeyF11 &&
    data->keys->is_fullscreen_pressed == sfTrue) {
        data->window->is_fullscreen = sfFalse;
        data->keys->is_fullscreen_pressed = sfFalse;
        sfRenderWindow_close(data->window->window);
        data->window->mode = (sfVideoMode){WIDTH, HEIGHT, 32};
        data->window->window = sfRenderWindow_create(data->window->mode,
        "My_RPG", sfClose | sfResize, NULL);
    }
}

void check_key_pressed2(data_t *data)
{
    if (data->window->event.key.code == data->keys->up ||
    data->window->event.key.code == data->keys->up2)
        data->keys->up_pressed = sfTrue;
    if (data->window->event.key.code == data->keys->down ||
    data->window->event.key.code == data->keys->down2)
        data->keys->down_pressed = sfTrue;
    if (data->window->event.key.code == data->keys->left ||
    data->window->event.key.code == data->keys->left2)
        data->keys->left_pressed = sfTrue;
    if (data->window->event.key.code == data->keys->right ||
    data->window->event.key.code == data->keys->right2)
        data->keys->right_pressed = sfTrue;
    if (data->window->event.key.code == data->keys->shift)
        data->keys->shift_pressed = sfTrue;
    if (data->window->event.key.code == data->keys->interact)
        data->keys->interact_pressed = sfTrue;
    if (data->window->event.key.code == data->keys->menu)
        data->keys->is_menu_pressed = sfTrue;
    if (data->window->event.key.code == data->keys->back)
        data->keys->back_pressed = sfTrue;
}

static void set_scenes(data_t *data, int scene)
{
    if (data->scene == GAME) {
        data->prev_scene = GAME;
        data->scene = scene;
    } else if (data->scene == scene) {
        data->prev_scene = scene;
        data->pause->index = 0;
        data->pause->status = 0;
        data->pause->action_index = 0;
        data->scene = GAME;
    }
}

static void set_inits(data_t *data)
{
    if (data->prev_scene == PAUSE_INST) {
        data->scene = GAME;
        data->prev_scene = GAME;
        data->pause->index = 0;
        data->pause->status = 0;
        data->pause->action_index = 0;
    } else if (data->scene == GAME) {
        data->scene = PAUSE;
        data->prev_scene = PAUSE_INST;
        data->pause->index = 1;
        data->pause->status = 1;
    }
    data->keys->is_inventory_pressed = sfTrue;
}

void check_key_pressed(data_t *data)
{
    check_fullscreen_key(data);
    check_key_pressed2(data);
    if (data->window->event.key.code == data->keys->map)
        data->keys->is_map_pressed = sfTrue;
    if (data->window->event.key.code == sfKeyEscape) {
        data->keys->is_escape_pressed = sfTrue;
        set_scenes(data, PAUSE);
    }
    if (data->window->event.key.code == sfKeyI)
        set_inits(data);
    if (data->window->event.key.code == sfKeyG) {
        if (data->player->isgm == sfTrue)
            data->player->isgm = sfFalse;
        else
            data->player->isgm = sfTrue;
    }
    if (data->window->event.key.code == sfKeySpace)
        printf("x: %f y: %f\n", data->player->pos.x - data->soul->pos.x,
        data->player->pos.y - data->soul->pos.y);
}

void check_key_released2(data_t *data)
{
    if (data->window->event.key.code == data->keys->interact)
        data->keys->interact_pressed = sfFalse;
    if (data->window->event.key.code == sfKeyEscape)
        data->keys->is_escape_pressed = sfFalse;
    if (data->window->event.key.code == data->keys->menu)
        data->keys->is_menu_pressed = sfFalse;
    if (data->window->event.key.code == data->keys->map)
        data->keys->is_map_pressed = sfFalse;
    if (data->window->event.key.code == data->keys->back)
        data->keys->back_pressed = sfFalse;
    if (data->window->event.key.code == sfKeyI)
        data->keys->is_inventory_pressed = sfFalse;
}

void check_key_released(data_t *data)
{
    if (data->window->event.key.code == data->keys->up ||
    data->window->event.key.code == data->keys->up2)
        data->keys->up_pressed = sfFalse;
    if (data->window->event.key.code == data->keys->down ||
    data->window->event.key.code == data->keys->down2)
        data->keys->down_pressed = sfFalse;
    if (data->window->event.key.code == data->keys->left ||
    data->window->event.key.code == data->keys->left2)
        data->keys->left_pressed = sfFalse;
    if (data->window->event.key.code == data->keys->right ||
    data->window->event.key.code == data->keys->right2)
        data->keys->right_pressed = sfFalse;
    if (data->window->event.key.code == data->keys->shift)
        data->keys->shift_pressed = sfFalse;
    check_key_released2(data);
}
