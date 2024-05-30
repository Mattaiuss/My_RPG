/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** enemies
*/

#pragma once

#include "my.h"
#include "rpg.h"

#define NB_MOBS 4
#define NB_ATTACKS 2

#define EN_ATK data->current_enemy->atk
#define P_DEF data->player->def_cb
#define P_HP data->player->hp
#define DAMAGES (EN_ATK - P_DEF) < 1 ? 1 : (EN_ATK - P_DEF)
#define TMP_EN_DMG data->player->atk_cb - data->current_enemy->def
#define EN_DAMAGES TMP_EN_DMG < 1 ? 1 : TMP_EN_DMG

#define BOSS_ATK "assets/attacks/stick.png"

typedef enum attack_type_e {
    SLIME_ATTACK,
    SLIME_ATTACK2,
    SKELETON_ATTACK,
    SKELETON_ATTACK2,
    TREANT_ATTACK,
    TREANT_ATTACK2,
    BOSS_ATTACK,
    BOSS_ATTACK2,
} attack_type_t;

typedef enum mob_type_e {
    SLIME,
    SKEL,
    TRE,
    BOSS,
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
