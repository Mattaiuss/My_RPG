/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** spawn_enemy
*/

#include "../includes/rpg.h"
#include "../includes/my.h"
#include <stdlib.h>
#include <string.h>

void buttons_pos(data_t *data)
{
    sfVector2f pos = {data->player->pos.x, data->player->pos.y};

    for (int i = 0; i < 4; i++) {
        data->combat->buttons[i]->pos = (sfVector2f){pos.x - 450 + (i * 235.5),
            pos.y};
        sfSprite_setPosition(data->combat->buttons[i]->sprite,
        data->combat->buttons[i]->pos);
    }
    sfMusic_pause(data->music);
    sfMusic_play(data->combat_music);
}

void init_combat(data_t *data)
{
    int mob_type;
    int mob;

    mob_type = rand() % data->current_zone->nb_mob_types;
    mob = data->current_zone->mob_types[mob_type];
    data->current_enemy = malloc(sizeof(enemy_t));
    data->current_enemy = data->enemies[mob];
    sfSprite_setPosition(data->current_enemy->sprite,
    (sfVector2f){data->player->pos.x - 68, data->player->pos.y + 45});
    data->soul->pos = (sfVector2f){data->player->pos.x - 5,
        data->player->pos.y - 100};
    data->combat->status = 0;
    data->combat->pos = (sfVector2f){data->player->pos.x, data->player->pos.y};
    sfSprite_setPosition(data->soul->sprite, data->soul->pos);
    sfSprite_setPosition(data->current_zone->bg, (sfVector2f){
        data->player->pos.x - (WIDTH / 3) + 10,
        data->player->pos.y - (HEIGHT / 3) + 10});
    data->scene = COMBAT;
    buttons_pos(data);
    play_sound(data, "assets/btl.ogg");
}

void check_spawn_enemy(data_t *data)
{
    int rdm;

    if (data->current_zone == NULL)
        return;
    if (data->current_zone->nb_mobs == 0)
        return;
    rdm = rand() % data->current_zone->spawn_rate;
    if (rdm == 1) {
        init_combat(data);
    }
}
