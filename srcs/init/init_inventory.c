/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_inventory
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void set_item_box(data_t *data, box_t *box, int id)
{
    box->item = malloc(sizeof(item_t));
    box->item->id = id;
    box->item->name = data->item[box->item->id].name;
    box->item->description = data->item[box->item->id].description;
    box->item->type = data->item[box->item->id].type;
    box->item->weapon = data->item[box->item->id].weapon;
    box->item->drop_rate = data->item[box->item->id].drop_rate;
    box->item->atk = data->item[box->item->id].atk;
    box->item->def = data->item[box->item->id].def;
    box->item->hp = data->item[box->item->id].hp;
    box->item->gold = data->item[box->item->id].gold;
    box->item->texture = data->item[box->item->id].texture;
    box->item->sprite = data->item[box->item->id].sprite;
    if (box->item->id == 8 || box->item->id == 9)
        sfSprite_setScale(box->item->sprite, (sfVector2f){1.8, 1.8});
    else
        sfSprite_setScale(box->item->sprite, (sfVector2f){3.6, 3.6});
}

void init_inventory_items(data_t *data)
{
    for (int i = 0; i < 10; i++) {
        data->player->inventory->invento[i] = malloc(sizeof(box_t));
        data->player->inventory->invento[i]->shape = sfRectangleShape_create();
        data->player->inventory->invento[i]->pos = (sfVector2f){0, 0};
        data->player->inventory->invento[i]->size = (sfVector2f){0, 0};
        data->player->inventory->invento[i]->texture = NULL;
        data->player->inventory->invento[i]->sprite = NULL;
        if (i == 0)
            set_item_box(data, data->player->inventory->invento[i], 0);
        else
            data->player->inventory->invento[i] = NULL;
    }
}

void init_inventory_equipment(data_t *data)
{
    for (int i = 0; i < 2; i++) {
        data->player->inventory->equip[i] = malloc(sizeof(box_t));
        data->player->inventory->equip[i]->shape = sfRectangleShape_create();
        data->player->inventory->equip[i]->pos = (sfVector2f){0, 0};
        data->player->inventory->equip[i]->size = (sfVector2f){0, 0};
        data->player->inventory->equip[i]->texture = NULL;
        data->player->inventory->equip[i]->sprite = NULL;
        data->player->inventory->equip[i] = NULL;
    }
}

void init_inventory(data_t *data)
{
    data->player->inventory = malloc(sizeof(inventory_t));
    data->player->inventory->nb_held_items = 12;
    data->player->inventory->pos = (sfVector2f){0, 0};
    init_inventory_items(data);
    init_inventory_equipment(data);
}
