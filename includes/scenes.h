/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** scenes
*/

#pragma once

#include "my.h"

#define D_PAUSE data->pause
#define D_GAME data->game
#define D_MENU data->menu
#define D_CINEMATIC data->cinematic

#define PX data->pause->pos.x
#define PY data->pause->pos.y

#define TEXT sfTexture_createFromFile

typedef enum action_e {
    A_ATK,
    A_ACT,
    A_ITM,
    A_MRY,
} action_t;

typedef struct data_s data_t;

typedef struct button_s {
    int nb_states;
    int state;
    sfTexture *texture;
    sfIntRect *rect;
    sfSprite *sprite;
    sfVector2f pos;
    int scene;
    //pointeur sur fonction
    void (*callback)(data_t *data);
} button_t;

typedef struct param_s {
    int nb_buttons;
    button_t **buttons;
    sfSprite *bg_sprite;
    sfTexture *bg_texture;
} param_t;

typedef struct menu_s {
    int nb_buttons;
    button_t **buttons;
    sfTexture *background;
    sfSprite *bg_sprite;
} menu_t;

typedef struct game_s {
    sfTexture *map_bas_text;
    sfSprite *map_bas_sprite;
    sfTexture *map_haut_text;
    sfSprite *map_haut_sprite;
} game_t;

typedef struct pause_s {
    sfTexture *pause_menu_text;
    sfSprite *pause_menu_sprite;
    sfTexture *action_text;
    sfSprite *action_sprite;

    sfText *text;
    sfVector2f pos;

    int status;
    int index;
    int item_index;
    int action_index;
    int equip_index;
} pause_t;

typedef struct wave_s wave_t;

typedef struct combat_s {
    int status;
    sfClock *animation;
    sfClock *invul;

    sfBool rukia;
    sfBool byakuya;
    int rukia_used;
    int byakuya_used;

    sfSprite *f_square;
    sfTexture *f_texture;
    sfSprite *a_square;
    sfTexture *a_texture;

    sfVector2f pos;
    wave_t *current_wave;

    int index_button;
    button_t **buttons;
    sfClock *act_clock;
} combat_t;

typedef struct cinematic_s {
    int nb_frames;
    int frame;

    sfTexture *texture;
    sfSprite *sprite;

    sfClock *cinematic_clock;

    sfText *text;
} cinematic_t;
