/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** item_actions
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void drop_item(data_t *data, int index)
{
    data->player->inventory->invento[index] = NULL;
    data->pause->action_index = 0;
    data->pause->status = 1;
}

int check_if_inventory_is_full(data_t *data)
{
    int index = 0;

    for (; index < 10; index++) {
        if (data->player->inventory->invento[index] == NULL)
            return index;
    }
    return -1;
}

static void temporary_up_speed(data_t *data, int def)
{
    data->player->speed *= def;
    data->player->effect_clock = sfClock_create();
}

void use(data_t *data, int index)
{
    if (data->player->hp == data->player->max_hp &&
    data->player->inventory->invento[index]->item->weapon == HEAL)
        return;
    if (data->player->inventory->invento[index]->item->hp > 0) {
        data->player->hp += data->player->inventory->invento[index]->item->hp;
        if (data->player->hp > data->player->max_hp)
            data->player->hp = data->player->max_hp;
    }
    if (data->player->inventory->invento[index]->item->def > 0) {
        if (data->player->speed != 2) {
            data->player->effect_clock = sfClock_create();
            data->player->inventory->invento[index] = NULL;
            return;
        }
        temporary_up_speed(data, PL->inventory->invento[index]->item->def);
    }
    data->player->inventory->invento[index] = NULL;
}

void equip_item(data_t *data, int index, int equip_index)
{
    int place = 0;
    box_t *tmp = NULL;

    if (D_PAUSE->item_index < 10) {
        if (PL->inventory->invento[index]->item->type != CONSUMABLE) {
            tmp = data->player->inventory->equip[equip_index];
            PL->inventory->equip[equip_index] = PL->inventory->invento[index];
            data->player->inventory->invento[index] = tmp;
        } else
            use(data, index);
    } else {
        place = check_if_inventory_is_full(data);
        if (place == -1)
            return;
        PL->inventory->invento[place] = PL->inventory->equip[equip_index];
        data->player->inventory->equip[equip_index] = NULL;
    }
    data->pause->equip_index = 0;
    data->pause->status = 1;
}

void display_item_infos(data_t *data, box_t *tmp)
{
    item_texts_t texts = allocate_item_texts(data, tmp);

    set_sprites(data, tmp);
    draw_texts(data, texts, tmp);
    free(texts.name);
    free(texts.desc);
    free(texts.type);
    free(texts.atk);
    free(texts.def);
    free(texts.hp);
    free(texts.gold);
    sfSprite_setScale(data->pause->action_sprite, (sfVector2f){0.2, 0.2});
}
