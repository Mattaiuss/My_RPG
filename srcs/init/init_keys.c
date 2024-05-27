/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_keys
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void init_keys2(data_t *data)
{
    data->keys->up_pressed = sfFalse;
    data->keys->down_pressed = sfFalse;
    data->keys->left_pressed = sfFalse;
    data->keys->right_pressed = sfFalse;
    data->keys->shift_pressed = sfFalse;
    data->keys->interact_pressed = sfFalse;
    data->keys->is_inventory_pressed = sfFalse;
    data->keys->is_escape_pressed = sfFalse;
    data->keys->is_map_pressed = sfFalse;
    data->keys->is_menu_pressed = sfFalse;
    data->keys->left_click = sfFalse;
    data->keys->is_fullscreen_pressed = sfFalse;
    data->keys->back_pressed = sfFalse;
    data->keys->is_dialogue_pressed = sfFalse;
}

void init_keys(data_t *data)
{
    data->keys = malloc(sizeof(keys_t));
    data->keys->up = sfKeyZ;
    data->keys->up2 = sfKeyUp;
    data->keys->down = sfKeyS;
    data->keys->down2 = sfKeyDown;
    data->keys->left = sfKeyQ;
    data->keys->left2 = sfKeyLeft;
    data->keys->right = sfKeyD;
    data->keys->right2 = sfKeyRight;
    data->keys->shift = sfKeyLShift;
    data->keys->interact = sfKeyE;
    data->keys->inventory = sfKeyI;
    data->keys->menu = sfKeyA;
    data->keys->map = sfKeyM;
    data->keys->fullscreen = sfKeyF11;
    data->keys->back = sfKeyA;
    data->keys->dialogue = sfKeyK;
    init_keys2(data);
}
