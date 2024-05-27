/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_items
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

static void init_items6(data_t *data)
{
    init_item_info(16, "Iron Helmet", "An iron helmet", data);
    init_item_type(16, EQUIP, NONE, data);
    init_item_atk(16, 0, data);
    init_item_def_hp(16, 25, 0, data);
    init_item_gold_drop_rate(16, 40, 0.1, data);
    init_item_info(17, "Perfect Helmet", "A perfect helmet", data);
    init_item_type(17, EQUIP, NONE, data);
    init_item_atk(17, 0, data);
    init_item_def_hp(17, 40, 0, data);
    init_item_gold_drop_rate(17, 60, 0.1, data);
}

static void init_items5(data_t *data)
{
    init_item_info(13, "Knight Potion", "Heal 50 hp", data);
    init_item_type(13, CONSUMABLE, HEAL, data);
    init_item_atk(13, 0, data);
    init_item_def_hp(13, 0, 50, data);
    init_item_gold_drop_rate(13, 50, 0.1, data);
    init_item_info(14,
    "Speed Potion", "Speed increased by 100% for 10 seconds", data);
    init_item_type(14, CONSUMABLE, BOOST, data);
    init_item_atk(14, 0, data);
    init_item_def_hp(14, 2, 0, data);
    init_item_gold_drop_rate(14, 20, 0.1, data);
    init_item_info(15, "Helmet", "A helmet", data);
    init_item_type(15, EQUIP, NONE, data);
    init_item_atk(15, 0, data);
    init_item_def_hp(15, 15, 0, data);
    init_item_gold_drop_rate(15, 25, 0.1, data);
    init_items6(data);
}

void init_items4(data_t *data)
{
    init_item_def_hp(9, 0, 0, data);
    init_item_gold_drop_rate(9, 10000, 0.1, data);
    init_item_info(10, "Magic Wand", "A magic wand", data);
    init_item_type(10, EQUIP, MAGIC, data);
    init_item_atk(10, 20, data);
    init_item_def_hp(10, 0, 0, data);
    init_item_gold_drop_rate(10, 20, 0.1, data);
    init_item_info(11, "Magic Book", "A mysterious magic book", data);
    init_item_type(11, EQUIP, MAGIC, data);
    init_item_atk(11, 40, data);
    init_item_def_hp(11, 0, 0, data);
    init_item_gold_drop_rate(11, 60, 0.1, data);
    init_item_info(12, "Heal Potion", "Heal 10 hp", data);
    init_item_type(12, CONSUMABLE, HEAL, data);
    init_item_atk(12, 0, data);
    init_item_def_hp(12, 0, 10, data);
    init_item_gold_drop_rate(12, 10, 0.1, data);
    init_items5(data);
}

void init_items3(data_t *data)
{
    init_item_gold_drop_rate(5, 20, 0.1, data);
    init_item_info(6, "Great Sword", "A great sword", data);
    init_item_type(6, EQUIP, SWORD, data);
    init_item_atk(6, 40, data);
    init_item_def_hp(6, -5, 0, data);
    init_item_gold_drop_rate(6, 40, 0.1, data);
    init_item_info(7, "Demonic Sword", "A demonic sword", data);
    init_item_type(7, EQUIP, SWORD, data);
    init_item_atk(7, 50, data);
    init_item_def_hp(7, -10, 0, data);
    init_item_gold_drop_rate(7, 80, 0.1, data);
    init_item_info(8, "Senbonzakura", BYAKUYA, data);
    init_item_type(8, EQUIP, SWORD, data);
    init_item_atk(8, 85, data);
    init_item_def_hp(8, 0, 0, data);
    init_item_gold_drop_rate(8, 10000, 0.1, data);
    init_item_info(9, "Sode No Shirayuki", RUKIA, data);
    init_item_type(9, EQUIP, SWORD, data);
    init_item_atk(9, 99, data);
    init_items4(data);
}

void init_items2(data_t *data)
{
    init_item_info(2, "Sword", "A sword", data);
    init_item_type(2, EQUIP, SWORD, data);
    init_item_atk(2, 10, data);
    init_item_def_hp(2, 0, 0, data);
    init_item_gold_drop_rate(2, 10, 0.1, data);
    init_item_info(3, "Shield", "A shield", data);
    init_item_type(3, EQUIP, NONE, data);
    init_item_atk(3, 0, data);
    init_item_def_hp(3, 8, 0, data);
    init_item_gold_drop_rate(3, 10, 0.1, data);
    init_item_info(4, "Iron Sword", "A special iron sword", data);
    init_item_type(4, EQUIP, SWORD, data);
    init_item_atk(4, 25, data);
    init_item_def_hp(4, 0, 0, data);
    init_item_gold_drop_rate(4, 20, 0.1, data);
    init_item_info(5, "Iron Shield", "An iron shield", data);
    init_item_type(5, EQUIP, NONE, data);
    init_item_atk(5, 0, data);
    init_item_def_hp(5, 20, 0, data);
    init_items3(data);
}

void init_items(data_t *data)
{
    data->item = malloc(sizeof(item_t) * data->nb_entities[2]);
    for (int i = 0; i < data->nb_entities[2]; i++) {
        data->item[i].id = i;
        data->item[i].sprite = sfSprite_create();
        data->item[i].texture = sfTexture_createFromFile(
            my_super_str_cat_int(ITEMS, i, ".png"), NULL);
        sfSprite_setTexture(data->item[i].sprite, data->item[i].texture,
        sfTrue);
    }
    init_item_info(0, "Broken sword", "A broken sword", data);
    init_item_type(0, EQUIP, SWORD, data);
    init_item_atk(0, 5, data);
    init_item_def_hp(0, 0, 0, data);
    init_item_gold_drop_rate(0, 3, 0.1, data);
    init_item_info(1, "Broken shield", "A broken shield", data);
    init_item_type(1, EQUIP, NONE, data);
    init_item_atk(1, 0, data);
    init_item_def_hp(1, 4, 0, data);
    init_item_gold_drop_rate(1, 3, 0.1, data);
    init_items2(data);
}
