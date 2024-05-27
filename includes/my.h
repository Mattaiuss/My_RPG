/*
** EPITECH PROJECT, 2024
** .h file
** File description:
** function file
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Network.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Window.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Context.h>
#include <SFML/Window/Cursor.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "characters.h"
#include "rpg.h"

#define JOYSTICK_THRESHOLD 50
#define WIDTH 1600
#define HEIGHT 900
#define WIN data->window->window

#define MAP_WIDTH sfTexture_getSize(data->game->map_text).x
#define MAP_HEIGHT sfTexture_getSize(data->game->map_text).y

#define BUTTON_S "assets/menu/button.png"
#define MENU_S "assets/menu/bg1.jpg"
#define SETTINGS_S "assets/menu/settings.png"
#define CURSOR "assets/menu/cursor.png"

#define ITEMS "assets/items/item"

#define MAP_BAS "assets/game/mapbas.png"
#define MAP_HAUT "assets/game/maphaut.png"

#define NB_ZONES 2

#define BYAKUYA3 " it multiplies your atk by 1.5."
#define BYAKUYA2 " if you attack with this equipped weapon," BYAKUYA3
#define BYAKUYA "A flower with a thousand petals. Once per battle," BYAKUYA2

#define RUKIA3 " if you attack with this equipped weapon, you play again."
#define RUKIA2 "13th division captain, Rukia Kuchiki. Once per battle," RUKIA3
#define RUKIA "A Zapakuto from the soul society of the " RUKIA2

typedef struct item_texts_s {
    char *name;
    char *desc;
    char *type;
    char *atk;
    char *def;
    char *hp;
    char *gold;
} item_texts_t;

typedef enum {
    QUEST,
    EQUIP,
    CONSUMABLE
} item_type_t;

typedef enum {
    NONE,
    SWORD,
    MAGIC,
    HEAL,
    BOOST
} weapon_t;

//lib/my_super_str_cat.c
/**
 * Concatenates a string, an integer, and an extension.
 * @param string The initial string.
 * @param value The integer to concatenate.
 * @param extension The extension to concatenate.
 * @return The concatenated string.
 */
char *my_super_str_cat_int(const char *string,
    int value, const char *extension);

int my_strlen(char const *str);
char *int_to_str(int nb, int mode);

typedef struct data_s data_t;
typedef struct button_s button_t;
typedef struct player_s player_t;


typedef struct param_s param_t;
typedef struct menu_s menu_t;
typedef struct game_s game_t;
typedef struct pause_s pause_t;
typedef struct combat_s combat_t;

void init_items(data_t *data);
void init_inventory(data_t *data);
void init_pause(data_t *data);
void init_game(data_t *data);
void init_menu(data_t *data);
void init_fight(data_t *data);
void init_params(data_t *data);
void init_keys(data_t *data);
void init_player(data_t *data);
void init_basics(data_t *data);
void init_soul(data_t *data);
void init_npc(data_t *data);

void init_item_def_hp(int id, int def, int hp, data_t *data);
void init_item_gold_drop_rate(int id, int gold, float drop_rate, data_t *data);
void init_item_info(int id, char *name, char *description, data_t *data);
void init_item_type(int id, item_type_t type, weapon_t weapon, data_t *data);
void init_item_atk(int id, int atk, data_t *data);
void init_zones(data_t *data);

int check_if_inventory_is_full(data_t *data);

void settings(data_t *data);
void menu(data_t *data);
void game(data_t *data);
void combat(data_t *data);
void set_gameover(data_t *data);
void set_karmaover(data_t *data);
void set_mercyover(data_t *data);
void fight(data_t *data);
void pause_wind(data_t *data);
void draw_pause_texts(data_t *data);
void draw_text(data_t *data, char *str, sfVector2f pos, int index);
void drawitm_text(data_t *data, char *str, sfVector2f pos, int index);
void drawact_text(data_t *data, char *str, sfVector2f pos, int index);
void display_pause_stats(data_t *data);
void reset_view_temp(data_t *data);
void move_index(data_t *data);
void move_item_index(data_t *data);
void move_act_index(data_t *data);
void move_equip_index(data_t *data);
void drawequip_text(data_t *data, char *str, sfVector2f pos, int index);
void drop_item(data_t *data, int index);
void equip_item(data_t *data, int index, int equip_index);
void display_item_infos(data_t *data, box_t *tmp);
void display_item_menu(data_t *data);
void disp_equip_menu(data_t *data);
void draw_sprite_game(data_t *data);
void draw_pause(data_t *data);
void draw_sprite_menu(data_t *data);
void display_pause_item(data_t *data);
void draw_saves(data_t *data);
void check_effect_clock(data_t *data);
void restart_music(data_t *data);

//srcs/pause/draw_item_infos.c
void draw_texts(data_t *data, item_texts_t txt, box_t *tmp);
void set_sprites(data_t *data, box_t *tmp);
item_texts_t allocate_item_texts(data_t *data, box_t *tmp);
int val_id_item_compens(int id);

void start_game(data_t *data);
void quit_game(data_t *data);
void params(data_t *data);
void return_menu(data_t *data);
void choose_save(data_t *data);

sfBool is_hover(button_t *button, data_t *data);
void set_mouse_rect(data_t *data);
void change_cursor(data_t *data);
void manage_events(data_t *data);
void check_key_released(data_t *data);
void check_key_pressed(data_t *data);

sfBool check_collision(data_t *data, int x, int y);
void move_map(data_t *data);
void is_not_moving(data_t *data);
void move_rect(player_t *player, int min, int max);

void is_p_in_zone(data_t *data);
void check_spawn_enemy(data_t *data);

void init_zone2(data_t *data);
void init_zone1(data_t *data);

void init_monsters(data_t *data);
typedef struct attack_s attack_t;
attack_t *copy_attack(attack_t *attack, char *path);
void init_slime(data_t *data);
void do_action(data_t *data);

//lib/manage_line.c
char *allocate_text(char *str, char *text);
int find_last_space_within_width(sfText *text, char *str, float width);
char *add_newline_if_needed(sfText *text, sfSprite *sprite, char *str);
int count_newlines(char *str);

void print_sword_effect(void);
void print_magic_effect(void);
void print_punch_effect(void);
void print_rukia_effect(void);
void print_byakuya_effect(void);

void disp_additionnal(data_t *data);
void display_go(data_t *data);

void destroy_param(param_t *param);
void destroy_menu(menu_t *menu);
void destroy_game(game_t *game);
void destroy_pause(pause_t *pause);
void destroy_combat(combat_t *combat);
void destroy_all(data_t *data);
