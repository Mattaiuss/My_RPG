/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_item_infos
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void init_item_info(int id, char *name, char *description, data_t *data)
{
    data->item[id].name = name;
    data->item[id].description = description;
}

void init_item_type(int id, item_type_t type, weapon_t weapon, data_t *data)
{
    data->item[id].type = type;
    if (type == EQUIP)
        data->item[id].weapon = weapon;
    else if (type == CONSUMABLE)
        data->item[id].weapon = weapon;
    else
        data->item[id].weapon = 0;
}

void init_item_def_hp(int id, int def, int hp, data_t *data)
{
    data->item[id].def = def;
    data->item[id].hp = hp;
}

void init_item_gold_drop_rate(int id, int gold, float drop_rate, data_t *data)
{
    data->item[id].gold = gold;
    data->item[id].drop_rate = drop_rate;
}

void init_item_atk(int id, int atk, data_t *data)
{
    data->item[id].atk = atk;
}
