/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** pause_texts
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"
#include <string.h>

static void disp_item(data_t *data, int j)
{
    if (j < 10) {
        if (data->player->inventory->invento[j] == NULL) {
            drawitm_text(data, "---------------------", (sfVector2f){
                D_PAUSE->pos.x + 340, D_PAUSE->pos.y + 33 + j * 27}, j);
            return;
        }
        drawitm_text(data, data->player->inventory->invento[j]->item->name,
        (sfVector2f){D_PAUSE->pos.x + 340, D_PAUSE->pos.y + 33 + j
        * 27}, j);
    } else {
        if (data->player->inventory->equip[j - 10] == NULL) {
            drawitm_text(data, "---------------------", (sfVector2f){
                D_PAUSE->pos.x + 340, D_PAUSE->pos.y + 33 + j * 28}, j);
            return;
        }
        drawitm_text(data, data->player->inventory->equip[j - 10]->item->name,
        (sfVector2f){D_PAUSE->pos.x + 340, D_PAUSE->pos.y + 33 + j * 28}, j);
    }
}

static void disp_items(data_t *data)
{
    sfText_setCharacterSize(data->pause->text, 19);
    for (int j = 0; j != data->player->inventory->nb_held_items; j++) {
        disp_item(data, j);
    }
    if (data->pause->status == 4)
        display_item_infos(data,
        data->player->inventory->invento[data->pause->item_index]);
}

static void act_fonc(data_t *data)
{
    if (data->pause->action_index == 0 && data->pause->item_index >= 10)
        equip_item(data, data->pause->item_index - 10,
        data->pause->item_index - 10);
    if (data->pause->action_index == 1)
        drop_item(data, data->pause->item_index);
    if (data->pause->action_index == 2)
        data->pause->status = 4;
    sfSleep((sfTime){110000});
    data->keys->interact_pressed = sfFalse;
    return;
}

static void is_act_pressed(data_t *data)
{
    if (data->keys->interact_pressed && data->pause->status == 2) {
        if (data->pause->action_index == 0 && data->pause->item_index < 10 &&
        data->player->inventory->invento[data->pause->item_index]->item->type
        != CONSUMABLE) {
            data->pause->status = 3;
        }
        if (data->pause->action_index == 0 && data->pause->item_index < 10 &&
        data->player->inventory->invento[data->pause->item_index]->item->type
        == CONSUMABLE) {
            equip_item(data, data->pause->item_index, data->pause->item_index);
        }
        act_fonc(data);
    }
    if (data->keys->interact_pressed && data->pause->status == 3) {
        equip_item(data, data->pause->item_index, data->pause->equip_index);
        sfSleep((sfTime){110000});
        data->keys->interact_pressed = sfFalse;
    }
}

void display_pause_item(data_t *data)
{
    move_item_index(data);
    if (data->player->inventory->nb_held_items == 0) {
        sfText_setCharacterSize(data->pause->text, 20);
        draw_text(data, "No item", (sfVector2f){data->pause->pos.x + 440,
        data->pause->pos.y + 35}, -1);
        return;
    }
    if (data->pause->status == 2 || data->pause->status == 3) {
        move_act_index(data);
        is_act_pressed(data);
        if (data->player->inventory->invento[data->pause->item_index] != NULL)
            display_item_menu(data);
    }
    if (data->pause->status == 3) {
        move_equip_index(data);
        disp_equip_menu(data);
    }
    disp_items(data);
}

static void index_4(data_t *data)
{
    if (data->pause->index == 3)
        write(1, "SAVE\n", 5);
    if (data->pause->index == 4) {
        data->prev_scene = PAUSE;
        data->scene = MENU;
        data->pause->index = 0;
        data->pause->status = 0;
        reset_view_temp(data);
    }
}

static void draw_second_square(data_t *data)
{
    draw_text(data, int_to_str(data->player->gold, 0),
    (sfVector2f){data->pause->pos.x + 75, data->pause->pos.y + 110}, -1);
    if (data->pause->status == 0)
        return;
    if (data->pause->index == 0)
        display_pause_stats(data);
    if (data->pause->index == 1) {
        display_pause_item(data);
    }
    if (data->pause->index == 2) {
        data->prev_scene = PAUSE;
        data->pause->index = 0;
        data->pause->status = 0;
        data->pause->action_index = 0;
        data->scene = SETTINGS;
        reset_view_temp(data);
    }
    index_4(data);
}

int hp_arm(data_t *data, int prev_hp)
{
    int hp = prev_hp;

    if (data->player->inventory->equip[0] != NULL)
        hp += data->player->inventory->equip[0]->item->hp;
    if (data->player->inventory->equip[1] != NULL)
        hp += data->player->inventory->equip[1]->item->hp;
    return hp < 1 ? 1 : hp;
}

static void draw_first_square(data_t *data)
{
    sfText_setCharacterSize(data->pause->text, 20);
    draw_text(data, data->player->name, (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 20}, -1);
    sfText_setCharacterSize(data->pause->text, 15);
    draw_text(data, "LV", (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 60}, -1);
    draw_text(data, int_to_str(data->player->lv, 0),
    (sfVector2f){data->pause->pos.x + 75, data->pause->pos.y + 60}, -1);
    draw_text(data, "HP", (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 85}, -1);
    draw_text(data, int_to_str(data->player->hp, 0),
    (sfVector2f){data->pause->pos.x + 75, data->pause->pos.y + 85}, -1);
    draw_text(data, ":", (sfVector2f){data->pause->pos.x + 112,
    data->pause->pos.y + 85}, -1);
    draw_text(data, int_to_str(data->player->max_hp, 0),
    (sfVector2f){data->pause->pos.x + 120, data->pause->pos.y + 85}, -1);
    draw_text(data, "G", (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 110}, -1);
    draw_second_square(data);
}

void draw_pause_texts(data_t *data)
{
    draw_first_square(data);
    sfText_setCharacterSize(data->pause->text, 30);
    draw_text(data, "STAT", (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 190}, 0);
    draw_text(data, "ITEM", (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 230}, 1);
    draw_text(data, "SETT", (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 270}, 2);
    draw_text(data, "SAVE", (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 310}, 3);
    draw_text(data, "MENU", (sfVector2f){data->pause->pos.x + 25,
    data->pause->pos.y + 350}, 4);
    sfText_destroy(data->pause->text);
}
