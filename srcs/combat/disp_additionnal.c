/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** disp_additionnal
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void disp_player_hp(data_t *data)
{
    sfRectangleShape *full_hp = sfRectangleShape_create();
    sfRectangleShape *hp = sfRectangleShape_create();
    int p_hp = data->player->hp;
    int p_max_hp = data->player->max_hp;
    sfVector2f pos = {data->player->pos.x - 95, data->player->pos.y - 250};

    sfRectangleShape_setSize(full_hp, (sfVector2f){200, 20});
    sfRectangleShape_setSize(hp, (sfVector2f){p_hp * 200 / p_max_hp, 20});
    sfRectangleShape_setFillColor(full_hp, sfColor_fromRGB(75, 75, 75));
    sfRectangleShape_setFillColor(hp, sfColor_fromRGB(0, 255, 0));
    sfRectangleShape_setPosition(full_hp, pos);
    sfRectangleShape_setPosition(hp, pos);
    sfRenderWindow_drawRectangleShape(data->window->window, full_hp, NULL);
    sfRenderWindow_drawRectangleShape(data->window->window, hp, NULL);
    sfRectangleShape_destroy(full_hp);
    sfRectangleShape_destroy(hp);
}

void disp_enemy_hp(data_t *data)
{
    sfRectangleShape *full_hp = sfRectangleShape_create();
    sfRectangleShape *hp = sfRectangleShape_create();
    int e_hp = data->current_enemy->life;
    int e_max_hp = data->current_enemy->max_life;
    sfVector2f pos = {data->player->pos.x - 95, data->player->pos.y + 200};

    sfRectangleShape_setSize(full_hp, (sfVector2f){200, 20});
    sfRectangleShape_setSize(hp, (sfVector2f){e_hp * 200 / e_max_hp, 20});
    sfRectangleShape_setFillColor(full_hp, sfColor_fromRGB(75, 75, 75));
    sfRectangleShape_setFillColor(hp, sfColor_fromRGB(255, 0, 0));
    sfRectangleShape_setPosition(full_hp, pos);
    sfRectangleShape_setPosition(hp, pos);
    sfRenderWindow_drawRectangleShape(data->window->window, full_hp, NULL);
    sfRenderWindow_drawRectangleShape(data->window->window, hp, NULL);
    sfRectangleShape_destroy(full_hp);
    sfRectangleShape_destroy(hp);
}

void disp_karma(data_t *data)
{
    sfRectangleShape *full_karma = sfRectangleShape_create();
    sfRectangleShape *karma = sfRectangleShape_create();
    int p_karma = (data->current_enemy->act - data->current_enemy->max_act)
    * -1;
    int p_max_karma = data->current_enemy->max_act;
    sfVector2f pos = {data->player->pos.x - 95, data->player->pos.y + 220};
    int result = p_karma == 0 ? 0 : p_karma * 200 / p_max_karma;

    sfRectangleShape_setSize(full_karma, (sfVector2f){200, 20});
    sfRectangleShape_setSize(karma, (sfVector2f){result, 20});
    sfRectangleShape_setFillColor(full_karma, sfColor_fromRGB(75, 75, 75));
    sfRectangleShape_setFillColor(karma, sfColor_fromRGB(0, 0, 255));
    sfRectangleShape_setPosition(full_karma, pos);
    sfRectangleShape_setPosition(karma, pos);
    sfRenderWindow_drawRectangleShape(data->window->window, full_karma, NULL);
    sfRenderWindow_drawRectangleShape(data->window->window, karma, NULL);
    sfRectangleShape_destroy(full_karma);
    sfRectangleShape_destroy(karma);
}

void disp_additionnal(data_t *data)
{
    disp_player_hp(data);
    disp_enemy_hp(data);
    disp_karma(data);
}
