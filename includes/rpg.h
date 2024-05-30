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
#include "npcs.h"
#include "save.h"

#define DESC1 "Try moving in all directions\nwith arrows or "
#define DESC2 "Open the pause menu by pressing\nthe 'Esc' key."
#define DESC3 "Equip the sword in the inventory\nin your hand."
#define DESC4 "Go north the village to find\nthe forest."
#define DESC5 "Explore the forest and fight\n or spare 3 enemies.\n("
#define DESC6 "Look in the forest for an\nold man."
#define DESC7 "Go east of the village to find\nthe wheat field."
#define DESC8 "Defeat or spare 5 more enemies.\n("
#define DESC9 "Explore further to find and \nfight the soldier."
#define DESC10 "Kill or spare the soldier to\nfinish the game."

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
    DIALOGUE,
    SHOP,
    END,
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

typedef struct data_s data_t;

typedef struct quest_s {
    char *title;
    char *desc;
    void (*func)(data_t *data);
    struct quest_s *next;
} quest_t;

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
    sfSoundBuffer *buffer;
    sfSound *sound;

    player_t *player;
    int nb_entities[3];
    int mob_killed;
    sfSprite *dialogue_sprite;
    sfTexture *dialogue_texture;
    soul_t *soul;
    item_t *item;

    zone_t **zones;
    zone_t *current_zone;

    enemy_t **enemies;
    enemy_t *current_enemy;

    npc_t **npcs;
    npc_t *current_npc;

    int *collision_map;

    quest_t *quest;
    int ret;
    int quest_index;

    int vol;
    button_t **volume;
    button_t **binds;
} data_t;

void push_back_quest(quest_t *head, quest_t *new);
