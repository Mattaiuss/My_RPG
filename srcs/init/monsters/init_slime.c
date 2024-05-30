/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_slime
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"

static void set_wave1(data_t *data)
{
    data->enemies[SLIME]->waves[0] = malloc(sizeof(wave_t));
    data->enemies[SLIME]->waves[0]->attacks = malloc(sizeof(attack_t *) * 2);
    data->enemies[SLIME]->waves[0]->nb_attacks = 2;
    data->enemies[SLIME]->waves[0]->clock = sfClock_create();
    data->enemies[SLIME]->waves[0]->time = sfMilliseconds(2000);
    data->enemies[SLIME]->waves[0]->attacks[0] = malloc(sizeof(attack_t));
    data->enemies[SLIME]->waves[0]->attacks[0] = copy_attack(
        data->enemies[SLIME]->waves[0]->attacks[0],
        "assets/attacks/slime1.png");
    data->enemies[SLIME]->waves[0]->attacks[0]->pos = (sfVector2f){20, 100};
    data->enemies[SLIME]->waves[0]->attacks[0]->og_pos = (sfVector2f){20, 100};
    data->enemies[SLIME]->waves[0]->attacks[0]->dir = (sfVector2f){0, -3};
    data->enemies[SLIME]->waves[0]->attacks[1] = malloc(sizeof(attack_t));
    data->enemies[SLIME]->waves[0]->attacks[1] = copy_attack(
        data->enemies[SLIME]->waves[0]->attacks[1],
        "assets/attacks/slime1.png");
    data->enemies[SLIME]->waves[0]->attacks[1]->pos = (sfVector2f){-20, 100};
    data->enemies[SLIME]->waves[0]->attacks[1]->og_pos =
    (sfVector2f){-20, 100};
    data->enemies[SLIME]->waves[0]->attacks[1]->dir = (sfVector2f){0, -3};
}

static void set_wave2(data_t *data)
{
    data->enemies[SLIME]->waves[1] = malloc(sizeof(wave_t));
    data->enemies[SLIME]->waves[1]->attacks = malloc(sizeof(attack_t *) * 2);
    data->enemies[SLIME]->waves[1]->nb_attacks = 2;
    data->enemies[SLIME]->waves[1]->clock = sfClock_create();
    data->enemies[SLIME]->waves[1]->time = sfMilliseconds(2000);
    data->enemies[SLIME]->waves[1]->attacks[0] = malloc(sizeof(attack_t));
    data->enemies[SLIME]->waves[1]->attacks[0] = copy_attack(
        data->enemies[SLIME]->waves[1]->attacks[0],
        "assets/attacks/slime1.png");
    data->enemies[SLIME]->waves[1]->attacks[0]->pos = (sfVector2f){100, 30};
    data->enemies[SLIME]->waves[1]->attacks[0]->og_pos = (sfVector2f){100, 30};
    data->enemies[SLIME]->waves[1]->attacks[0]->dir = (sfVector2f){-2, -2};
    data->enemies[SLIME]->waves[1]->attacks[1] = malloc(sizeof(attack_t));
    data->enemies[SLIME]->waves[1]->attacks[1] = copy_attack(
        data->enemies[SLIME]->waves[1]->attacks[1],
        "assets/attacks/slime1.png");
    data->enemies[SLIME]->waves[1]->attacks[1]->pos = (sfVector2f){-100, 30};
    data->enemies[SLIME]->waves[1]->attacks[1]->og_pos =
    (sfVector2f){-100, 30};
    data->enemies[SLIME]->waves[1]->attacks[1]->dir = (sfVector2f){2, -2};
}

static void init_slime2(data_t *data)
{
    data->enemies[SLIME]->texture = sfTexture_createFromFile(
        "assets/monsters/slime.png", NULL);
    data->enemies[SLIME]->sprite = sfSprite_create();
    sfSprite_setTexture(data->enemies[SLIME]->sprite,
    data->enemies[SLIME]->texture, sfTrue);
    sfSprite_setScale(data->enemies[SLIME]->sprite, (sfVector2f){5, 5});
    data->enemies[SLIME]->nb_waves = 2;
    data->enemies[SLIME]->waves = malloc(sizeof(wave_t *) *
    data->enemies[SLIME]->nb_waves);
    data->enemies[SLIME]->nb_drop_item = 4;
    data->enemies[SLIME]->drop_item = malloc(sizeof(item_t *) *
    data->enemies[SLIME]->nb_drop_item);
    data->enemies[SLIME]->drop_item[0] = 0;
    data->enemies[SLIME]->drop_item[1] = 1;
    data->enemies[SLIME]->drop_item[2] = 2;
    data->enemies[SLIME]->drop_item[3] = 3;
}

void init_slime(data_t *data)
{
    data->enemies[SLIME] = malloc(sizeof(enemy_t));
    data->enemies[SLIME]->name = "Slime";
    data->enemies[SLIME]->pos = (sfVector2f){100, 100};
    data->enemies[SLIME]->act = 3;
    data->enemies[SLIME]->max_act = data->enemies[SLIME]->act;
    data->enemies[SLIME]->atk = 20;
    data->enemies[SLIME]->def = 10;
    data->enemies[SLIME]->life = 50;
    data->enemies[SLIME]->max_life = 50;
    data->enemies[SLIME]->xp = 10;
    data->enemies[SLIME]->gold = 5;
    init_slime2(data);
    set_wave1(data);
    set_wave2(data);
}
