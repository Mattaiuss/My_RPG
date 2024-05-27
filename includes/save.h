/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** save
*/

#pragma once

#include "my.h"
#include "rpg.h"

typedef struct save_s {
    int save_id;
    sfVector2f pos;
    int hp;
    int hp_max;
    int xp;
    int xp_max;
    int level;
    int gold;
    int attack;
    int defense;
    int speed;
    int quest_index;
    int zone1_mobsleft;
    int zone2_mobsleft;
    int zone3_mobsleft;
    int zone4_mobsleft;
    //donner des id aux items pour les récup??
} save_t;
