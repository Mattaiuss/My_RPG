/*
** EPITECH PROJECT, 2024
** .h file content struct
** File description:
** rpg
*/

#pragma once
#include "my.h"
#include "scenes.h"
#include "characters.h"
#include "enemies.h"
#include "save.h"

typedef enum {
    PACIFIST,
    NEUTRAL,
    GENOCIDE,
} difficulty_t;

typedef enum {
    CINEMATIC,
    MENU,
    SAVES,
    SETTINGS,
    GAME,
    COMBAT,
    PAUSE,
    PAUSE_INST,
    GAME_OVER,
} scene_t;

typedef struct mouse_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2i posi;
    sfVector2f pos;
} mouse_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    mouse_t *mouse;
    sfEvent event;
    sfClock *clock;
    sfVector2f mouse_pos;
    sfView *view;
    sfView *gameview;
    sfVector2f view_pos;
    sfBool is_fullscreen;
} window_t;

typedef struct keys_s {
    sfKeyCode up;
    sfKeyCode up2;
    sfKeyCode down;
    sfKeyCode down2;
    sfKeyCode left;
    sfKeyCode left2;
    sfKeyCode right;
    sfKeyCode right2;
    sfKeyCode shift;
    sfKeyCode interact;
    sfKeyCode inventory;
    sfKeyCode menu;
    sfKeyCode map;
    sfKeyCode fullscreen;
    sfKeyCode back;
    sfKeyCode dialogue;

    sfBool up_pressed;
    sfBool down_pressed;
    sfBool left_pressed;
    sfBool right_pressed;
    sfBool shift_pressed;
    sfBool interact_pressed;
    sfBool is_inventory_pressed;
    sfBool is_escape_pressed;
    sfBool is_map_pressed;
    sfBool is_menu_pressed;
    sfBool left_click;
    sfBool is_fullscreen_pressed;
    sfBool back_pressed;
    sfBool is_dialogue_pressed;
} keys_t;

typedef struct data_s {
    window_t *window;
    int scene;
    int prev_scene;
    param_t *param[1];

    cinematic_t *cinematic;
    menu_t *menu;
    game_t *game;
    pause_t *pause;
    combat_t *combat;

    keys_t *keys;
    sfFont *font;
    sfVector2i mouse_pos;

    sfMusic *music;
    sfMusic *combat_music;

    player_t *player;
    int nb_entities[3];
    npc_t *npc;
    soul_t *soul;
    item_t *item;
    zone_t **zones;
    zone_t *current_zone;

    enemy_t **enemies;
    enemy_t *current_enemy;

    int *collision_map;
} data_t;
