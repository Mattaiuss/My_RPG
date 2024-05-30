/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** set_endfight
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void stop_music(data_t *data)
{
    int rdm = rand() % 36;

    sfMusic_stop(data->combat_music);
    sfMusic_play(data->music);
    if (rdm > 17)
        return;
    add_new_item(data, search_first_place(10, data), rdm);
    return;
}

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
    if (strcmp(data->current_enemy->name, "BOSS") == 0) {
        data->scene = END;
    }
    data->current_enemy = NULL;
    data->mob_killed ++;
    data->player->karma += 10;
    if (data->player->xp >= next_level) {
        data->player->lv += 1;
        data->player->xp -= next_level;
        data->player->max_hp += 10;
        data->player->hp = data->player->max_hp;
        next_level += 10;
        play_sound(data, "assets/lvl.ogg");
    }
    return stop_music(data);
}

void set_karmaover(data_t *data)
{
    data->current_enemy->life = 0;
    data->scene = GAME;
    data->combat->status = 0;
    data->current_enemy->life = data->current_enemy->max_life;
    data->current_enemy->act = data->current_enemy->max_act;
    data->player->xp += data->current_enemy->xp / 2;
    data->player->gold += data->current_enemy->gold * 2;
    if (strcmp(data->current_enemy->name, "BOSS") == 0) {
        data->scene = END;
    }
    data->current_enemy = NULL;
    data->mob_killed ++;
    data->player->karma -= 10;
    sfMusic_stop(data->combat_music);
    sfMusic_play(data->music);
    return;
}

void set_mercyover(data_t *data)
{
    if (data->quest->title[6] == '9')
        return;
    data->scene = GAME;
    data->combat->status = 0;
    data->current_enemy->life = data->current_enemy->max_life;
    data->current_enemy->act = data->current_enemy->max_act;
    sfMusic_stop(data->combat_music);
    sfMusic_play(data->music);
    return;
}
