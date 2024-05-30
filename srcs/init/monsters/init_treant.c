/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_treant
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"

static void set_wave1_2(data_t *data)
{
    data->enemies[TRE]->waves[0]->attacks[1]->dir = (sfVector2f){3, 0};
    data->enemies[TRE]->waves[0]->attacks[2] = malloc(sizeof(attack_t));
    data->enemies[TRE]->waves[0]->attacks[2] = copy_attack(
        data->enemies[TRE]->waves[0]->attacks[2],
        "assets/attacks/stick.png");
    data->enemies[TRE]->waves[0]->attacks[2]->pos = (sfVector2f){250, -110};
    data->enemies[TRE]->waves[0]->attacks[2]->og_pos = (sfVector2f){250, -110};
    data->enemies[TRE]->waves[0]->attacks[2]->dir = (sfVector2f){-6, 0};
    data->enemies[TRE]->waves[0]->attacks[3] = malloc(sizeof(attack_t));
    data->enemies[TRE]->waves[0]->attacks[3] = copy_attack(
        data->enemies[TRE]->waves[0]->attacks[3],
        "assets/attacks/stick.png");
    data->enemies[TRE]->waves[0]->attacks[3]->pos = (sfVector2f){-250, -110};
    data->enemies[TRE]->waves[0]->attacks[3]->og_pos =
    (sfVector2f){-250, -110};
    data->enemies[TRE]->waves[0]->attacks[3]->dir = (sfVector2f){6, 0};
}

static void set_wave1(data_t *data)
{
    data->enemies[TRE]->waves[0] = malloc(sizeof(wave_t));
    data->enemies[TRE]->waves[0]->attacks = malloc(sizeof(attack_t *) * 4);
    data->enemies[TRE]->waves[0]->nb_attacks = 4;
    data->enemies[TRE]->waves[0]->clock = sfClock_create();
    data->enemies[TRE]->waves[0]->time = sfMilliseconds(2500);
    data->enemies[TRE]->waves[0]->attacks[0] = malloc(sizeof(attack_t));
    data->enemies[TRE]->waves[0]->attacks[0] = copy_attack(
        data->enemies[TRE]->waves[0]->attacks[0],
        "assets/attacks/stick.png");
    data->enemies[TRE]->waves[0]->attacks[0]->pos = (sfVector2f){200, -185};
    data->enemies[TRE]->waves[0]->attacks[0]->og_pos = (sfVector2f){200, -185};
    data->enemies[TRE]->waves[0]->attacks[0]->dir = (sfVector2f){-3, 0};
    data->enemies[TRE]->waves[0]->attacks[1] = malloc(sizeof(attack_t));
    data->enemies[TRE]->waves[0]->attacks[1] = copy_attack(
        data->enemies[TRE]->waves[0]->attacks[1],
        "assets/attacks/stick.png");
    data->enemies[TRE]->waves[0]->attacks[1]->pos = (sfVector2f){-200, -50};
    data->enemies[TRE]->waves[0]->attacks[1]->og_pos =
    (sfVector2f){-200, -50};
    set_wave1_2(data);
}

static void set_wave2_2(data_t *data)
{
    data->enemies[TRE]->waves[1]->attacks[1]->dir = (sfVector2f){0, 3};
    data->enemies[TRE]->waves[1]->attacks[2] = malloc(sizeof(attack_t));
    data->enemies[TRE]->waves[1]->attacks[2] = copy_attack(
        data->enemies[TRE]->waves[1]->attacks[2],
        "assets/attacks/stick.png");
    data->enemies[TRE]->waves[1]->attacks[2]->pos = (sfVector2f){0, 250};
    data->enemies[TRE]->waves[1]->attacks[2]->og_pos = (sfVector2f){0, 250};
    data->enemies[TRE]->waves[1]->attacks[2]->dir = (sfVector2f){0, -7};
}

static void set_wave2(data_t *data)
{
    data->enemies[TRE]->waves[1] = malloc(sizeof(wave_t));
    data->enemies[TRE]->waves[1]->attacks = malloc(sizeof(attack_t *) * 3);
    data->enemies[TRE]->waves[1]->nb_attacks = 3;
    data->enemies[TRE]->waves[1]->clock = sfClock_create();
    data->enemies[TRE]->waves[1]->time = sfMilliseconds(2500);
    data->enemies[TRE]->waves[1]->attacks[0] = malloc(sizeof(attack_t));
    data->enemies[TRE]->waves[1]->attacks[0] = copy_attack(
        data->enemies[TRE]->waves[1]->attacks[0],
        "assets/attacks/stick.png");
    data->enemies[TRE]->waves[1]->attacks[0]->pos = (sfVector2f){50, -250};
    data->enemies[TRE]->waves[1]->attacks[0]->og_pos = (sfVector2f){50, -250};
    data->enemies[TRE]->waves[1]->attacks[0]->dir = (sfVector2f){0, 3};
    data->enemies[TRE]->waves[1]->attacks[1] = malloc(sizeof(attack_t));
    data->enemies[TRE]->waves[1]->attacks[1] = copy_attack(
        data->enemies[TRE]->waves[1]->attacks[1],
        "assets/attacks/stick.png");
    data->enemies[TRE]->waves[1]->attacks[1]->pos = (sfVector2f){-80, -250};
    data->enemies[TRE]->waves[1]->attacks[1]->og_pos =
    (sfVector2f){-80, -250};
    set_wave2_2(data);
}

void init_treant2(data_t *data)
{
    data->enemies[TRE]->texture = sfTexture_createFromFile(
        "assets/monsters/tree.png", NULL);
    data->enemies[TRE]->sprite = sfSprite_create();
    sfSprite_setTexture(data->enemies[TRE]->sprite,
    data->enemies[TRE]->texture, sfTrue);
    sfSprite_setScale(data->enemies[TRE]->sprite, (sfVector2f){0.5, 0.5});
    data->enemies[TRE]->nb_waves = 2;
    data->enemies[TRE]->waves = malloc(sizeof(wave_t *) *
    data->enemies[TRE]->nb_waves);
    data->enemies[TRE]->nb_drop_item = 4;
    data->enemies[TRE]->drop_item = malloc(sizeof(item_t *) *
    data->enemies[TRE]->nb_drop_item);
    data->enemies[TRE]->drop_item[0] = 0;
    data->enemies[TRE]->drop_item[1] = 1;
    data->enemies[TRE]->drop_item[2] = 2;
    data->enemies[TRE]->drop_item[3] = 3;
}

void init_treant(data_t *data)
{
    data->enemies[TRE] = malloc(sizeof(enemy_t));
    data->enemies[TRE]->name = "treant";
    data->enemies[TRE]->pos = (sfVector2f){100, 200};
    data->enemies[TRE]->act = 3;
    data->enemies[TRE]->max_act = data->enemies[TRE]->act;
    data->enemies[TRE]->atk = 35;
    data->enemies[TRE]->def = 5;
    data->enemies[TRE]->life = 35;
    data->enemies[TRE]->max_life = 35;
    data->enemies[TRE]->xp = 20;
    data->enemies[TRE]->gold = 20;
    init_treant2(data);
    set_wave1(data);
    set_wave2(data);
}
