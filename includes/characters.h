/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** characters
*/

#pragma once
#include "my.h"

#define PL data->player
#define SOUL data->soul
#define ENEMY data->current_enemy

typedef struct item_s {
    int id;
    char *name;
    char *description;
    int type; //quest, equip, consumable
    int weapon; //if equip
    float drop_rate; //if enemy drop / gacha
    int atk;
    int def;
    int hp;
    int gold; //cost if buyable
    sfTexture *texture;
    sfSprite *sprite;
} item_t;

typedef struct box_s {
    sfRectangleShape *shape;
    sfVector2f pos;
    sfVector2f size;
    sfTexture *texture;
    sfSprite *sprite;
    sfColor color;
    item_t *item;
} box_t;

typedef struct inventory_s {
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    int nb_held_items;
    box_t *invento[10];
    box_t *equip[2];
} inventory_t;

typedef struct conversation_s {
    int status;
    int nb_lines;
    sfText **text;
    struct conversation_t *next;
} conversation_t;

typedef struct npc_s {
    char *name;
    sfVector2f pos;

    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;

    struct npc_t *next;
} npc_t;

typedef struct soul_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;

    int life;
    int max_life;
} soul_t;

typedef struct player_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;

    sfClock *clock;
    sfClock *effect_clock;
    sfTime pause_time;
    int is_paused;

    char *name;
    int speed;
    int ROUTE;
    int atk;
    int atk_cb;
    int def;
    int def_cb;
    int hp;
    int hp_cb;
    int max_hp;
    int karma;
    int lv;
    int xp;
    int gold;
    inventory_t *inventory;
    sfBool isgm;
} player_t;
