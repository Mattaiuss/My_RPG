/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_param
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void init_params3(data_t *data)
{
    data->param[0]->buttons[0]->pos = (sfVector2f){WIDTH / 4 - 60,
    HEIGHT / 4 - 80};
    sfSprite_setPosition(data->param[0]->buttons[0]->sprite,
    data->param[0]->buttons[0]->pos);
    data->param[0]->buttons[0]->callback = &return_menu;
    data->param[0]->buttons[0]->scene = MENU;
}

void init_params2(data_t *data)
{
    data->param[0]->buttons[0] = malloc(sizeof(button_t));
    data->param[0]->buttons[0]->nb_states = 2;
    data->param[0]->buttons[0]->state = 0;
    data->param[0]->buttons[0]->texture = malloc(sizeof(sfTexture *) *
    data->param[0]->buttons[0]->nb_states);
    data->param[0]->buttons[0]->rect = malloc(sizeof(sfIntRect) *
    data->param[0]->buttons[0]->nb_states);
    data->param[0]->buttons[0]->sprite = sfSprite_create();
    data->param[0]->buttons[0]->texture =
    sfTexture_createFromFile(BUTTON_S, NULL);
    data->param[0]->buttons[0]->rect[0] = (sfIntRect){1280 * 9, 0, 1280, 320};
    data->param[0]->buttons[0]->rect[1] = (sfIntRect){1280 * 10, 0, 1280, 320};
    sfSprite_setTexture(data->param[0]->buttons[0]->sprite,
    data->param[0]->buttons[0]->texture, sfTrue);
    sfSprite_setTextureRect(data->param[0]->buttons[0]->sprite,
    data->param[0]->buttons[0]->rect[0]);
    sfSprite_setScale(data->param[0]->buttons[0]->sprite,
    (sfVector2f){0.1, 0.1});
    init_params3(data);
}

void init_params(data_t *data)
{
    sfVector2u texture_size;
    sfVector2u window_size;
    sfVector2f scale;

    data->vol = 50;
    for (int i = 0; i < 1; i++)
        data->param[i] = malloc(sizeof(param_t));
    data->param[0]->bg_sprite = sfSprite_create();
    data->param[0]->bg_texture = sfTexture_createFromFile(SETTINGS_S, NULL);
    sfSprite_setTexture(data->param[0]->bg_sprite,
    data->param[0]->bg_texture, sfTrue);
    texture_size = sfTexture_getSize(data->param[0]->bg_texture);
    window_size = sfRenderWindow_getSize(data->window->window);
    scale.x = (float)window_size.x / texture_size.x;
    scale.y = (float)window_size.y / texture_size.y;
    sfSprite_setScale(data->param[0]->bg_sprite, scale);
    data->param[0]->nb_buttons = 1;
    data->param[0]->buttons = malloc(sizeof(button_t) *
    data->param[0]->nb_buttons);
    init_params2(data);
}
