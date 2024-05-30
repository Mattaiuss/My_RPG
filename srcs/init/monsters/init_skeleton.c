/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_skeleton
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"

static void set_wave1_2(data_t *data)
{
    data->enemies[SKEL]->waves[0]->attacks[1]->pos = (sfVector2f){200, -200};
    data->enemies[SKEL]->waves[0]->attacks[1]->dir = (sfVector2f){-2.5, 0};
    data->enemies[SKEL]->waves[0]->attacks[2] = malloc(sizeof(attack_t));
    data->enemies[SKEL]->waves[0]->attacks[2] = copy_attack(
        data->enemies[SKEL]->waves[0]->attacks[2],
        "assets/attacks/bone.png");
    data->enemies[SKEL]->waves[0]->attacks[2]->pos = (sfVector2f){-200, -200};
    data->enemies[SKEL]->waves[0]->attacks[2]->og_pos = (sfVector2f){-200,
    -200};
    data->enemies[SKEL]->waves[0]->attacks[2]->dir = (sfVector2f){1.5, 0};
    data->enemies[SKEL]->waves[0]->attacks[3] = malloc(sizeof(attack_t));
    data->enemies[SKEL]->waves[0]->attacks[3] = copy_attack(
        data->enemies[SKEL]->waves[0]->attacks[3],
        "assets/attacks/bone.png");
    data->enemies[SKEL]->waves[0]->attacks[3]->pos = (sfVector2f){-200, -100};
    data->enemies[SKEL]->waves[0]->attacks[3]->og_pos = (sfVector2f){-200,
    -100};
    data->enemies[SKEL]->waves[0]->attacks[3]->dir = (sfVector2f){3, 0};
}

static void set_wave1(data_t *data)
{
    data->enemies[SKEL]->waves[0] = malloc(sizeof(wave_t));
    data->enemies[SKEL]->waves[0]->attacks = malloc(sizeof(attack_t *) * 4);
    data->enemies[SKEL]->waves[0]->nb_attacks = 4;
    data->enemies[SKEL]->waves[0]->clock = sfClock_create();
    data->enemies[SKEL]->waves[0]->time = sfMilliseconds(3000);
    data->enemies[SKEL]->waves[0]->attacks[0] = malloc(sizeof(attack_t));
    data->enemies[SKEL]->waves[0]->attacks[0] = copy_attack(
        data->enemies[SKEL]->waves[0]->attacks[0],
        "assets/attacks/bone.png");
    data->enemies[SKEL]->waves[0]->attacks[0]->pos = (sfVector2f){200, -100};
    data->enemies[SKEL]->waves[0]->attacks[0]->og_pos = (sfVector2f){200,
    -100};
    data->enemies[SKEL]->waves[0]->attacks[0]->dir = (sfVector2f){-1.5, 0};
    data->enemies[SKEL]->waves[0]->attacks[1] = malloc(sizeof(attack_t));
    data->enemies[SKEL]->waves[0]->attacks[1] = copy_attack(
        data->enemies[SKEL]->waves[0]->attacks[1],
        "assets/attacks/bone.png");
    data->enemies[SKEL]->waves[0]->attacks[1]->og_pos =
    (sfVector2f){200, -200};
    set_wave1_2(data);
}

static void init_skeleton2(data_t *data)
{
    data->enemies[SKEL]->texture = sfTexture_createFromFile(
        "assets/monsters/skeleton.png", NULL);
    data->enemies[SKEL]->sprite = sfSprite_create();
    sfSprite_setTexture(data->enemies[SKEL]->sprite,
    data->enemies[SKEL]->texture, sfTrue);
    sfSprite_setScale(data->enemies[SKEL]->sprite, (sfVector2f){0.6, 0.6});
    data->enemies[SKEL]->nb_waves = 1;
    data->enemies[SKEL]->waves = malloc(sizeof(wave_t *) *
    data->enemies[SKEL]->nb_waves);
    data->enemies[SKEL]->nb_drop_item = 4;
    data->enemies[SKEL]->drop_item = malloc(sizeof(item_t *) *
    data->enemies[SKEL]->nb_drop_item);
    data->enemies[SKEL]->drop_item[0] = 0;
    data->enemies[SKEL]->drop_item[1] = 1;
    data->enemies[SKEL]->drop_item[2] = 2;
    data->enemies[SKEL]->drop_item[3] = 3;
}

void init_skeleton(data_t *data)
{
    data->enemies[SKEL] = malloc(sizeof(enemy_t));
    data->enemies[SKEL]->name = "Skeleton";
    data->enemies[SKEL]->pos = (sfVector2f){200, 100};
    data->enemies[SKEL]->act = 5;
    data->enemies[SKEL]->max_act = data->enemies[SKEL]->act;
    data->enemies[SKEL]->atk = 40;
    data->enemies[SKEL]->def = 30;
    data->enemies[SKEL]->life = 10;
    data->enemies[SKEL]->max_life = 10;
    data->enemies[SKEL]->xp = 20;
    data->enemies[SKEL]->gold = 20;
    init_skeleton2(data);
    set_wave1(data);
}
