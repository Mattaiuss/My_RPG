/*
** EPITECH PROJECT, 2024
** .h file content struct
** File description:
** npc
*/

#pragma once

#include "my.h"
#include "rpg.h"

#define NB_NPC 18

#define RES_QUEST npc->dial_file[1] : npc->dial_file[0]
#define CHECK_QUEST is_npc_quest(data, npc) == sfTrue ? RES_QUEST

#define DIALOGUE_POS data->player->pos.x - 450, data->player->pos.y + 170

typedef enum type_npc_e {
    SIMP,
    MARCHAND,
} type_npc_t;

typedef enum npc_name_e {
    ELYSANDE,
    THORNE,
    ASTRID,
    BALIAN,
    MORGANE,
    LYANNA,
    GRIMBOK,
    ALARIC,
    THALIA,
    CEDRIC,
    LOTHAR,
    ELOWEN,
    NYMERIA,
    ISOLDE,
    SELENA,
    REDERIC,
    GARETH,
    DARIUS,
} npc_name_t;

typedef struct npc_s {
    char *name;
    int id;
    type_npc_t type;
    sfVector2f pos;
    sfBool quest_npc;

    int nb_dialogues;
    char **dial_file;

    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} npc_t;
