/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** set_endfight
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void set_gameover(data_t *data)
{
    static int next_level = 20;

    data->current_enemy->life = 0;
    data->scene = GAME;
    data->combat->status = 0;
    data->current_enemy->life = data->current_enemy->max_life;
    data->current_enemy->act = data->current_enemy->max_act;
    data->player->xp += data->current_enemy->xp;
    data->player->gold += data->current_enemy->gold;
    data->current_enemy = NULL;
    data->current_zone->nb_mobs --;
    data->player->karma += 10;
    if (data->player->xp >= next_level) {
        data->player->lv += 1;
        data->player->xp -= next_level;
        data->player->max_hp += 10;
        data->player->hp = data->player->max_hp;
        next_level += 10;
    }
    return;
}

void set_karmaover(data_t *data)
{
    data->current_enemy->life = 0;
    data->scene = GAME;
    data->combat->status = 0;
    data->current_enemy->life = data->current_enemy->max_life;
    data->current_enemy->act = data->current_enemy->max_act;
    data->player->xp += data->current_enemy->xp / 10;
    data->player->gold += data->current_enemy->gold;
    data->current_enemy = NULL;
    data->current_zone->nb_mobs --;
    data->player->karma -= 10;
    return;
}

void set_mercyover(data_t *data)
{
    data->scene = GAME;
    data->combat->status = 0;
    data->current_enemy->life = data->current_enemy->max_life;
    data->current_enemy->act = data->current_enemy->max_act;
    return;
}
