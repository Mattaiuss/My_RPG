/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** pause_index
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

static void move_item_index2(data_t *data)
{
    if (data->keys->interact_pressed &&
    data->player->inventory->invento[data->pause->item_index] != NULL) {
        data->pause->status ++;
        sfSleep((sfTime){110000});
        data->keys->interact_pressed = sfFalse;
    }
    if (data->keys->back_pressed) {
        data->pause->status --;
        sfSleep((sfTime){110000});
        data->keys->back_pressed = sfFalse;
    }
}

void move_item_index(data_t *data)
{
    if (data->pause->status != 1)
        return;
    if (data->keys->up_pressed && data->pause->item_index > 0) {
        data->pause->item_index--;
        sfSleep((sfTime){110000});
        data->keys->up_pressed = sfFalse;
    }
    if (data->keys->down_pressed && data->pause->item_index <
    data->player->inventory->nb_held_items - 1) {
        data->pause->item_index++;
        sfSleep((sfTime){110000});
        data->keys->down_pressed = sfFalse;
    }
    move_item_index2(data);
}

void move_act_index(data_t *data)
{
    if (data->pause->status != 2)
        return;
    if (data->keys->back_pressed && data->pause->status == 2) {
        data->pause->status --;
        data->pause->action_index = 0;
        sfSleep((sfTime){110000});
        data->keys->back_pressed = sfFalse;
    }
    if (data->keys->up_pressed && data->pause->action_index > 0) {
        data->pause->action_index--;
        sfSleep((sfTime){110000});
        data->keys->up_pressed = sfFalse;
    }
    if (data->keys->down_pressed && data->pause->action_index < 2) {
        data->pause->action_index++;
        sfSleep((sfTime){110000});
        data->keys->down_pressed = sfFalse;
    }
}

static void move_back2(data_t *data)
{
    if (data->pause->status == 3) {
        data->pause->status = 2;
        data->pause->equip_index = 0;
        sfSleep((sfTime){110000});
    }
    if (data->pause->status == 4) {
        data->pause->status = 2;
        sfSleep((sfTime){110000});
    }
    data->keys->back_pressed = sfFalse;
}

static void move_back_pressed(data_t *data)
{
    if (data->pause->status == 0 ||
    (data->prev_scene == PAUSE_INST && data->pause->status == 1)) {
        data->scene = GAME;
        data->prev_scene = PAUSE;
        data->pause->index = 0;
        data->pause->status = 0;
        data->pause->action_index = 0;
    }
    if (data->pause->status == 1) {
        data->pause->status = 0;
        data->pause->item_index = 0;
        sfSleep((sfTime){110000});
    }
    if (data->pause->status == 2) {
        data->pause->status = 1;
        data->pause->action_index = 0;
        sfSleep((sfTime){110000});
    }
    move_back2(data);
}

static void move_index2(data_t *data)
{
    if (data->keys->interact_pressed && data->pause->status == 0) {
        data->pause->status = 1;
        sfSleep((sfTime){110000});
        data->keys->interact_pressed = sfFalse;
    }
    if (data->keys->back_pressed) {
        move_back_pressed(data);
    }
}

void move_equip_index(data_t *data)
{
    if (data->keys->back_pressed || data->keys->shift_pressed) {
        data->pause->status = 2;
        sfSleep((sfTime){110000});
        data->pause->equip_index = 0;
        data->keys->back_pressed = sfFalse;
    } else if (data->keys->interact_pressed) {
        data->pause->status = 2;
        sfSleep((sfTime){110000});
        data->keys->interact_pressed = sfFalse;
    }
    if (data->keys->up_pressed && data->pause->equip_index > 0) {
        data->pause->equip_index--;
        sfSleep((sfTime){110000});
        data->keys->up_pressed = sfFalse;
    }
    if (data->keys->down_pressed && data->pause->equip_index < 1) {
        data->pause->equip_index++;
        sfSleep((sfTime){110000});
        data->keys->down_pressed = sfFalse;
    }
}

void move_index(data_t *data)
{
    if (data->keys->up_pressed && data->pause->index > 0 &&
    data->pause->status == 0) {
        data->pause->index--;
        sfSleep((sfTime){110000});
        data->keys->up_pressed = sfFalse;
    }
    if (data->keys->down_pressed && data->pause->index < 4 &&
    data->pause->status == 0) {
        data->pause->index++;
        sfSleep((sfTime){110000});
        data->keys->down_pressed = sfFalse;
    }
    move_index2(data);
}
