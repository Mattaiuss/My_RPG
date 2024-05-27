/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** enemies
*/

#pragma once

#include "my.h"
#include "rpg.h"

#define NB_MOBS 1
#define NB_MOB_TYPES 5
#define NB_ATTACKS 2

#define EN_ATK data->current_enemy->atk
#define P_DEF data->player->def
#define P_HP data->player->hp
#define ENEMY_DAMAGE (EN_ATK - P_DEF) > 0 ? (EN_ATK - P_DEF) : 1
#define DAMAGE_TAKEN P_HP - ENEMY_DAMAGE

typedef enum attack_type_e {
    SLIME_ATTACK,
    SLIME_ATTACK2,
    BUSH_ATTACK,
    BUSH_ATTACK2,
    SCARECROW_ATTACK,
    SCARECROW_ATTACK2,
    ARBRE_ATTACK,
    ARBRE_ATTACK2,
    KNGITH_ATTACK,
    KNGITH_ATTACK2,
} attack_type_t;

typedef enum mob_type_e {
    SLIME,
    ARBRE,
    BUSH,
    SCARECROW,
    KNGITH,
} mob_type_t;

typedef struct attack_s {
    sfVector2f pos;
    sfVector2f og_pos;
    sfVector2f dir;

    sfSprite *sprite;
    sfTexture *texture;
} attack_t;

typedef struct wave_s {
    attack_t **attacks;
    int nb_attacks;
    sfClock *clock;
    sfTime time;
} wave_t;

typedef struct enemy_s {
    char *name;
    sfVector2f pos;

    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;

    int atk;
    int def;
    int life;
    int max_life;
    int xp;
    int gold;
    int act;
    int max_act;
    int *drop_item;
    int nb_drop_item;

    wave_t **waves;
    int nb_waves;
} enemy_t;

typedef struct zone_s {

    int is_load;

    sfRectangleShape *shape;
    sfVector2f pos;
    sfVector2f size;

    int nb_mobs;
    int nb_mob_types;
    int spawn_rate;
    int *mob_types;

    sfSprite *bg;
    sfTexture *bg_text;
} zone_t;

void init_slime(data_t *data);
