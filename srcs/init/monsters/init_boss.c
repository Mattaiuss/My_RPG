/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_slime
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"

void set_wave1bis2(data_t *data)
{
    data->enemies[BOSS]->waves[0]->attacks[4] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[0]->attacks[4] = copy_attack(
        data->enemies[BOSS]->waves[0]->attacks[4],
        "assets/attacks/spear.png");
    data->enemies[BOSS]->waves[0]->attacks[4]->pos = (sfVector2f){-10, 100};
    data->enemies[BOSS]->waves[0]->attacks[4]->og_pos = (sfVector2f){-10,
    100};
    data->enemies[BOSS]->waves[0]->attacks[4]->dir = (sfVector2f){0, -4};
}

void set_wave1bis(data_t *data)
{
    data->enemies[BOSS]->waves[0]->attacks[1]->dir = (sfVector2f){0, -4};
    data->enemies[BOSS]->waves[0]->attacks[2] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[0]->attacks[2] = copy_attack(
        data->enemies[BOSS]->waves[0]->attacks[2],
        "assets/attacks/spear.png");
    data->enemies[BOSS]->waves[0]->attacks[2]->pos = (sfVector2f){-40, 100};
    data->enemies[BOSS]->waves[0]->attacks[2]->og_pos = (sfVector2f){-40, 100};
    data->enemies[BOSS]->waves[0]->attacks[2]->dir = (sfVector2f){0, -4};
    data->enemies[BOSS]->waves[0]->attacks[3] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[0]->attacks[3] = copy_attack(
        data->enemies[BOSS]->waves[0]->attacks[3],
        "assets/attacks/spear.png");
    data->enemies[BOSS]->waves[0]->attacks[3]->pos = (sfVector2f){-80, 100};
    data->enemies[BOSS]->waves[0]->attacks[3]->og_pos = (sfVector2f){-80,
    100};
    data->enemies[BOSS]->waves[0]->attacks[3]->dir = (sfVector2f){0, -4};
    set_wave1bis2(data);
}

static void set_wave1(data_t *data)
{
    data->enemies[BOSS]->waves[0] = malloc(sizeof(wave_t));
    data->enemies[BOSS]->waves[0]->attacks = malloc(sizeof(attack_t *) * 5);
    data->enemies[BOSS]->waves[0]->nb_attacks = 5;
    data->enemies[BOSS]->waves[0]->clock = sfClock_create();
    data->enemies[BOSS]->waves[0]->time = sfMilliseconds(2000);
    data->enemies[BOSS]->waves[0]->attacks[0] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[0]->attacks[0] = copy_attack(
        data->enemies[BOSS]->waves[0]->attacks[0],
        "assets/attacks/spear.png");
    data->enemies[BOSS]->waves[0]->attacks[0]->pos = (sfVector2f){90, 100};
    data->enemies[BOSS]->waves[0]->attacks[0]->og_pos = (sfVector2f){90, 100};
    data->enemies[BOSS]->waves[0]->attacks[0]->dir = (sfVector2f){0, -4};
    data->enemies[BOSS]->waves[0]->attacks[1] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[0]->attacks[1] = copy_attack(
        data->enemies[BOSS]->waves[0]->attacks[1],
        "assets/attacks/spear.png");
    data->enemies[BOSS]->waves[0]->attacks[1]->pos = (sfVector2f){40, 100};
    data->enemies[BOSS]->waves[0]->attacks[1]->og_pos =
    (sfVector2f){40, 100};
    set_wave1bis(data);
}

void set_wave2bis2(data_t *data)
{
    data->enemies[BOSS]->waves[1]->attacks[5] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[1]->attacks[5] = copy_attack(
        data->enemies[BOSS]->waves[1]->attacks[5],
        "assets/attacks/spear2.png");
    data->enemies[BOSS]->waves[1]->attacks[5]->pos = (sfVector2f){-100, 30};
    data->enemies[BOSS]->waves[1]->attacks[5]->og_pos =
    (sfVector2f){-300, -70};
    data->enemies[BOSS]->waves[1]->attacks[5]->dir = (sfVector2f){4, 0};
    data->enemies[BOSS]->waves[1]->attacks[6] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[1]->attacks[6] = copy_attack(
        data->enemies[BOSS]->waves[1]->attacks[6],
        "assets/attacks/spear2.png");
    data->enemies[BOSS]->waves[1]->attacks[6]->pos = (sfVector2f){-300, 30};
    data->enemies[BOSS]->waves[1]->attacks[6]->og_pos =
    (sfVector2f){-650, -70};
    data->enemies[BOSS]->waves[1]->attacks[6]->dir = (sfVector2f){4, 0};
    data->enemies[BOSS]->waves[1]->attacks[7] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[1]->attacks[7] = copy_attack(
        data->enemies[BOSS]->waves[1]->attacks[7],
        "assets/attacks/spear3.png");
    data->enemies[BOSS]->waves[1]->attacks[7]->pos = (sfVector2f){-100, 30};
    data->enemies[BOSS]->waves[1]->attacks[7]->og_pos =
    (sfVector2f){650, -100};
    data->enemies[BOSS]->waves[1]->attacks[7]->dir =
    (sfVector2f){-4, 0};
}

void wave2_bis(data_t *data)
{
    data->enemies[BOSS]->waves[1]->attacks[2] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[1]->attacks[2] = copy_attack(
        data->enemies[BOSS]->waves[1]->attacks[2],
        "assets/attacks/spear2.png");
    data->enemies[BOSS]->waves[1]->attacks[2]->pos = (sfVector2f){-100, 30};
    data->enemies[BOSS]->waves[1]->attacks[2]->og_pos =
    (sfVector2f){-50, -150};
    data->enemies[BOSS]->waves[1]->attacks[2]->dir = (sfVector2f){0, 0};
    data->enemies[BOSS]->waves[1]->attacks[3] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[1]->attacks[3] = copy_attack(
        data->enemies[BOSS]->waves[1]->attacks[3],
        "assets/attacks/spear.png");
    data->enemies[BOSS]->waves[1]->attacks[3]->pos = (sfVector2f){200, -130};
    data->enemies[BOSS]->waves[1]->attacks[3]->og_pos =
    (sfVector2f){80, -130};
    data->enemies[BOSS]->waves[1]->attacks[3]->dir = (sfVector2f){0, 0};
    data->enemies[BOSS]->waves[1]->attacks[4] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[1]->attacks[4] = copy_attack(
        data->enemies[BOSS]->waves[1]->attacks[4],
        "assets/attacks/spear3.png");
    data->enemies[BOSS]->waves[1]->attacks[4]->pos = (sfVector2f){100, -200};
    data->enemies[BOSS]->waves[1]->attacks[4]->og_pos =
    (sfVector2f){300, -120};
    data->enemies[BOSS]->waves[1]->attacks[4]->dir = (sfVector2f){-4, 0};
    set_wave2bis2(data);
}

static void set_wave2(data_t *data)
{
    data->enemies[BOSS]->waves[1] = malloc(sizeof(wave_t));
    data->enemies[BOSS]->waves[1]->attacks = malloc(sizeof(attack_t *) * 8);
    data->enemies[BOSS]->waves[1]->nb_attacks = 8;
    data->enemies[BOSS]->waves[1]->clock = sfClock_create();
    data->enemies[BOSS]->waves[1]->time = sfMilliseconds(3800);
    data->enemies[BOSS]->waves[1]->attacks[0] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[1]->attacks[0] = copy_attack(
        data->enemies[BOSS]->waves[1]->attacks[0],
        "assets/attacks/spear2.png");
    data->enemies[BOSS]->waves[1]->attacks[0]->pos = (sfVector2f){-30, -10};
    data->enemies[BOSS]->waves[1]->attacks[0]->og_pos = (sfVector2f){-50, -30};
    data->enemies[BOSS]->waves[1]->attacks[0]->dir = (sfVector2f){0, 0};
    data->enemies[BOSS]->waves[1]->attacks[1] = malloc(sizeof(attack_t));
    data->enemies[BOSS]->waves[1]->attacks[1] = copy_attack(
        data->enemies[BOSS]->waves[1]->attacks[1],
        "assets/attacks/spear.png");
    data->enemies[BOSS]->waves[1]->attacks[1]->pos = (sfVector2f){-100, -10};
    data->enemies[BOSS]->waves[1]->attacks[1]->og_pos =
    (sfVector2f){-75, -130};
    data->enemies[BOSS]->waves[1]->attacks[1]->dir = (sfVector2f){0, 0};
    wave2_bis(data);
}

static void init_boss2(data_t *data)
{
    data->enemies[BOSS]->texture = sfTexture_createFromFile(
        "assets/monsters/boss.png", NULL);
    data->enemies[BOSS]->sprite = sfSprite_create();
    sfSprite_setTexture(data->enemies[BOSS]->sprite,
    data->enemies[BOSS]->texture, sfTrue);
    sfSprite_setScale(data->enemies[BOSS]->sprite, (sfVector2f){2, 2});
    data->enemies[BOSS]->nb_waves = 2;
    data->enemies[BOSS]->waves = malloc(sizeof(wave_t *) *
    data->enemies[BOSS]->nb_waves);
    data->enemies[BOSS]->nb_drop_item = 4;
    data->enemies[BOSS]->drop_item = malloc(sizeof(item_t *) *
    data->enemies[BOSS]->nb_drop_item);
    data->enemies[BOSS]->drop_item[0] = 0;
    data->enemies[BOSS]->drop_item[1] = 1;
    data->enemies[BOSS]->drop_item[2] = 2;
    data->enemies[BOSS]->drop_item[3] = 3;
}

void init_boss(data_t *data)
{
    data->enemies[BOSS] = malloc(sizeof(enemy_t));
    data->enemies[BOSS]->name = "BOSS";
    data->enemies[BOSS]->pos = (sfVector2f){100, 100};
    data->enemies[BOSS]->act = 30;
    data->enemies[BOSS]->max_act = data->enemies[BOSS]->act;
    data->enemies[BOSS]->atk = 40;
    data->enemies[BOSS]->def = 25;
    data->enemies[BOSS]->life = 400;
    data->enemies[BOSS]->max_life = 400;
    data->enemies[BOSS]->xp = 100;
    data->enemies[BOSS]->gold = 500;
    init_boss2(data);
    set_wave1(data);
    set_wave2(data);
}
