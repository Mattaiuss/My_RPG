/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_volume
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void change_keymap(data_t *data)
{
    static int keymap = 0;

    if (is_hover(data->binds[0], data) == sfTrue)
        keymap = 0;
    if (is_hover(data->binds[1], data) == sfTrue)
        keymap = 1;
    if (keymap == 0) {
        data->keys->up = sfKeyZ;
        data->keys->down = sfKeyS;
        data->keys->left = sfKeyQ;
        data->keys->right = sfKeyD;
    }
    if (keymap == 1) {
        data->keys->up = sfKeyW;
        data->keys->down = sfKeyS;
        data->keys->left = sfKeyA;
        data->keys->right = sfKeyD;
    }
}

static void init_binds(data_t *data)
{
    data->binds = malloc(sizeof(button_t *) * 2);
    for (int i = 0; i < 2; i++) {
        data->binds[i] = malloc(sizeof(button_t));
        data->binds[i]->sprite = sfSprite_create();
    }
    data->binds[0]->texture = TEXT("assets/menu/azerty.png", NULL);
    data->binds[1]->texture = TEXT("assets/menu/qwerty.png", NULL);
    for (int i = 0; i < 2; i++) {
        sfSprite_setTexture(data->binds[i]->sprite,
        data->binds[i]->texture, sfTrue);
        sfSprite_setScale(data->binds[i]->sprite, (sfVector2f){2, 2});
    }
    data->binds[0]->pos = (sfVector2f){WIDTH / 2 + 150, HEIGHT / 2 - 100};
    data->binds[1]->pos = (sfVector2f){WIDTH / 2 + 350, HEIGHT / 2 - 100};
    sfSprite_setPosition(data->binds[0]->sprite, data->binds[0]->pos);
    sfSprite_setPosition(data->binds[1]->sprite, data->binds[1]->pos);
    data->binds[0]->callback = &change_keymap;
    data->binds[1]->callback = &change_keymap;
    data->binds[0]->scene = SETTINGS;
    data->binds[1]->scene = SETTINGS;
}

void volume(data_t *data)
{
    int add = 0;

    if (is_hover(data->volume[0], data) == sfTrue)
        add = 5;
    if (is_hover(data->volume[1], data) == sfTrue)
        add = -5;
    data->vol += add;
    if (data->vol > 100)
        data->vol = 100;
    if (data->vol < 0)
        data->vol = 0;
    sfMusic_setVolume(data->music, data->vol);
}

void init_volume(data_t *data)
{
    for (int i = 0; i < 2; i++) {
        data->volume[i] = malloc(sizeof(button_t));
        data->volume[i]->sprite = sfSprite_create();
    }
    data->volume[0]->texture = TEXT("assets/menu/plus.png", NULL);
    data->volume[1]->texture = TEXT("assets/menu/minus.png", NULL);
    for (int i = 0; i < 2; i++) {
        sfSprite_setTexture(data->volume[i]->sprite,
        data->volume[i]->texture, sfTrue);
        sfSprite_setScale(data->volume[i]->sprite, (sfVector2f){2, 2});
    }
    data->volume[0]->pos = (sfVector2f){WIDTH / 2 - 250, HEIGHT / 2 - 100};
    data->volume[1]->pos = (sfVector2f){WIDTH / 2 - 450, HEIGHT / 2 - 100};
    sfSprite_setPosition(data->volume[0]->sprite, data->volume[0]->pos);
    sfSprite_setPosition(data->volume[1]->sprite, data->volume[1]->pos);
    data->volume[0]->callback = &volume;
    data->volume[1]->callback = &volume;
    data->volume[0]->scene = SETTINGS;
    data->volume[1]->scene = SETTINGS;
    init_binds(data);
}
