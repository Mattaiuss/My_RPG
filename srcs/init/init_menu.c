/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_menu
*/

#include "../../includes/my.h"
#include "../../includes/rpg.h"

static void init_but0_2(data_t *data)
{
    sfSprite_setTexture(data->menu->buttons[0]->sprite,
    data->menu->buttons[0]->texture, sfTrue);
    sfSprite_setTextureRect(data->menu->buttons[0]->sprite,
    data->menu->buttons[0]->rect[0]);
    sfSprite_setScale(data->menu->buttons[0]->sprite, (sfVector2f){0.5, 0.5});
    data->menu->buttons[0]->pos = (sfVector2f){WIDTH / 4 - 350, HEIGHT / 3};
    sfSprite_setPosition(data->menu->buttons[0]->sprite,
    data->menu->buttons[0]->pos);
    data->menu->buttons[0]->callback = &start_game;
    data->menu->buttons[0]->scene = MENU;
}

void init_but0(data_t *data)
{
    data->menu->buttons[0] = malloc(sizeof(button_t));
    data->menu->buttons[0]->nb_states = 2;
    data->menu->buttons[0]->state = 0;
    data->menu->buttons[0]->texture = malloc(sizeof(sfTexture *) *
    data->menu->buttons[0]->nb_states);
    data->menu->buttons[0]->rect = malloc(sizeof(sfIntRect) *
    data->menu->buttons[0]->nb_states);
    data->menu->buttons[0]->sprite = sfSprite_create();
    data->menu->buttons[0]->texture = sfTexture_createFromFile(BUTTON_S, NULL);
    data->menu->buttons[0]->rect[0] = (sfIntRect){1280 * 0, 0, 1280, 320};
    data->menu->buttons[0]->rect[1] = (sfIntRect){1280 * 1, 0, 1280, 320};
    init_but0_2(data);
}

static void init_but1_2(data_t *data)
{
    sfSprite_setTexture(data->menu->buttons[1]->sprite,
    data->menu->buttons[1]->texture, sfTrue);
    sfSprite_setTextureRect(data->menu->buttons[1]->sprite,
    data->menu->buttons[1]->rect[0]);
    sfSprite_setScale(data->menu->buttons[1]->sprite, (sfVector2f){0.3, 0.3});
    data->menu->buttons[1]->pos = (sfVector2f){WIDTH / 4 - 225, HEIGHT / 1.9};
    sfSprite_setPosition(data->menu->buttons[1]->sprite,
    data->menu->buttons[1]->pos);
    data->menu->buttons[1]->callback = &params;
    data->menu->buttons[1]->scene = -1;
}

void init_but1(data_t *data)
{
    data->menu->buttons[1] = malloc(sizeof(button_t));
    data->menu->buttons[1]->nb_states = 2;
    data->menu->buttons[1]->state = 0;
    data->menu->buttons[1]->texture = malloc(sizeof(sfTexture *) *
    data->menu->buttons[1]->nb_states);
    data->menu->buttons[1]->rect = malloc(sizeof(sfIntRect) *
    data->menu->buttons[1]->nb_states);
    data->menu->buttons[1]->sprite = sfSprite_create();
    data->menu->buttons[1]->texture = sfTexture_createFromFile(BUTTON_S, NULL);
    data->menu->buttons[1]->rect[0] = (sfIntRect){1280 * 3, 0, 1280, 320};
    data->menu->buttons[1]->rect[1] = (sfIntRect){1280 * 4, 0, 1280, 320};
    init_but1_2(data);
}

static void init_but2_2(data_t *data)
{
    sfSprite_setTexture(data->menu->buttons[2]->sprite,
    data->menu->buttons[2]->texture, sfTrue);
    sfSprite_setTextureRect(data->menu->buttons[2]->sprite,
    data->menu->buttons[2]->rect[0]);
    sfSprite_setScale(data->menu->buttons[2]->sprite, (sfVector2f){0.3, 0.3});
    data->menu->buttons[2]->pos = (sfVector2f){WIDTH / 4 - 225,
    HEIGHT / 1.5 - 10};
    sfSprite_setPosition(data->menu->buttons[2]->sprite,
    data->menu->buttons[2]->pos);
    data->menu->buttons[2]->callback = &quit_game;
    data->menu->buttons[2]->scene = -1;
}

void init_but2(data_t *data)
{
    data->menu->buttons[2] = malloc(sizeof(button_t));
    data->menu->buttons[2]->nb_states = 2;
    data->menu->buttons[2]->state = 0;
    data->menu->buttons[2]->texture = malloc(sizeof(sfTexture *) *
    data->menu->buttons[2]->nb_states);
    data->menu->buttons[2]->rect = malloc(sizeof(sfIntRect) *
    data->menu->buttons[2]->nb_states);
    data->menu->buttons[2]->sprite = sfSprite_create();
    data->menu->buttons[2]->texture = sfTexture_createFromFile(BUTTON_S, NULL);
    data->menu->buttons[2]->rect[0] = (sfIntRect){1280 * 6, 0, 1280, 320};
    data->menu->buttons[2]->rect[1] = (sfIntRect){1280 * 7, 0, 1280, 320};
    init_but2_2(data);
}

void init_menu(data_t *data)
{
    data->menu = malloc(sizeof(menu_t));
    data->menu->bg_sprite = sfSprite_create();
    data->menu->background = sfTexture_createFromFile(MENU_S, NULL);
    sfSprite_setTexture(data->menu->bg_sprite, data->menu->background, sfTrue);
    sfSprite_setScale(data->menu->bg_sprite, (sfVector2f){2.2, 2.4});
    sfSprite_setPosition(data->menu->bg_sprite, (sfVector2f){-100, 0});
    data->menu->nb_buttons = 3;
    data->menu->buttons = malloc(sizeof(button_t) * data->menu->nb_buttons);
    init_but0(data);
    init_but1(data);
    init_but2(data);
}
