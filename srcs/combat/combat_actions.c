/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** combat_actions
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void check_start_act(data_t *data)
{
    data->combat->current_wave = data->current_enemy->waves[rand() %
    data->current_enemy->nb_waves];
    data->combat->status = 1;
    data->current_enemy->act -= 1;
    if (data->current_enemy->act == 0)
        return set_karmaover(data);
}

void act(data_t *data)
{
    check_start_act(data);
    for (int i = 0; i < data->combat->current_wave->nb_attacks; i ++) {
        data->combat->current_wave->attacks[i]->pos =
        data->combat->current_wave->attacks[i]->og_pos;
        data->combat->current_wave->attacks[i]->pos =
        (sfVector2f){data->player->pos.x +
        data->combat->current_wave->attacks[i]->pos.x,
        data->player->pos.y +
        data->combat->current_wave->attacks[i]->pos.y};
        sfSprite_setPosition(
            data->combat->current_wave->attacks[i]->sprite,
            data->combat->current_wave->attacks[i]->pos);
        data->soul->pos = (sfVector2f){data->player->pos.x - 5,
            data->player->pos.y - 100};
        sfSprite_setPosition(data->soul->sprite, data->soul->pos);
    }
    sfClock_restart(data->combat->animation);
    sfClock_restart(data->combat->current_wave->clock);
}

static int get_pot_id(data_t *data)
{
    int hp = data->player->hp;

    if (hp + 50 - data->player->max_hp > hp + 10 - data->player->max_hp)
        return 12;
    return 13;
}

static void check_hp_changestart(data_t *data, int copy)
{
    if (copy == data->player->hp)
        return;
    data->combat->current_wave = data->current_enemy->waves[rand() %
    data->current_enemy->nb_waves];
    data->combat->status = 1;
    for (int i = 0; i < data->combat->current_wave->nb_attacks; i ++) {
        data->combat->current_wave->attacks[i]->pos =
        data->combat->current_wave->attacks[i]->og_pos;
        data->combat->current_wave->attacks[i]->pos =
        (sfVector2f){data->player->pos.x +
        data->combat->current_wave->attacks[i]->pos.x,
        data->player->pos.y +
        data->combat->current_wave->attacks[i]->pos.y};
        sfSprite_setPosition(
            data->combat->current_wave->attacks[i]->sprite,
            data->combat->current_wave->attacks[i]->pos);
    }
    sfClock_restart(data->combat->animation);
    sfClock_restart(data->combat->current_wave->clock);
}

void item(data_t *data)
{
    int pot_id = get_pot_id(data);
    int copy = data->player->hp;

    if (data->player->hp == data->player->max_hp)
        return;
    for (int i = 0; i < 10; i ++) {
        if (data->player->inventory->invento[i] == NULL)
            continue;
        if (data->player->inventory->invento[i]->item->id == pot_id) {
            data->player->hp += pot_id == 12 ? 50 : 10;
            data->player->hp = data->player->hp > data->player->max_hp ?
            data->player->max_hp : data->player->hp;
            data->player->inventory->invento[i] = NULL;
            data->keys->interact_pressed = sfFalse;
        }
    }
    check_hp_changestart(data, copy);
}

void mercy(data_t *data)
{
    set_mercyover(data);
}

void do_action(data_t *data)
{
    if (data->combat->index_button == 0)
        fight(data);
    if (data->combat->index_button == 1)
        act(data);
    if (data->combat->index_button == 2)
        item(data);
    if (data->combat->index_button == 3)
        mercy(data);
}
