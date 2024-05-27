/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_characters
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void init_npc(data_t *data)
{
    data->combat->rukia = sfTrue;
    data->combat->rukia_used = 0;
    data->combat->byakuya = sfTrue;
    data->combat->byakuya_used = 0;
    data->nb_entities[0] = 0;
    for (int i = 0; i < data->nb_entities[0]; i++) {
        data->npc = malloc(sizeof(npc_t) * data->nb_entities[0]);
        data->npc[i].sprite = sfSprite_create();
        data->npc[i].texture =
        sfTexture_createFromFile(my_super_str_cat_int("npc", i, ".png"), NULL);
        sfSprite_setTexture(data->npc[i].sprite, data->npc[i].texture, sfTrue);
        data->npc[i].rect = (sfIntRect){0, 0, 548, 386};
        sfSprite_setTextureRect(data->npc[i].sprite, data->npc[i].rect);
        data->npc[i].pos = (sfVector2f){900, 450};
        sfSprite_setPosition(data->npc[i].sprite, data->npc[i].pos);
        sfSprite_setScale(data->npc[i].sprite, (sfVector2f){0.3, 0.3});
    }
}

void init_soul(data_t *data)
{
    data->soul = malloc(sizeof(soul_t));
    data->soul->sprite = sfSprite_create();
    data->soul->texture =
    sfTexture_createFromFile("assets/character/soul.png", NULL);
    sfSprite_setTexture(data->soul->sprite, data->soul->texture, sfTrue);
    sfSprite_setScale(data->soul->sprite, (sfVector2f){0.015, 0.015});
}

static void init_player2(data_t *data)
{
    data->player->atk = 15;
    data->player->atk_cb = data->player->atk;
    data->player->def = 15;
    data->player->def_cb = data->player->def;
    data->player->speed = 2;
    data->player->inventory = malloc(sizeof(inventory_t));
    data->player->inventory->nb_held_items = 0;
    data->player->isgm = sfFalse;
}

void init_player(data_t *data)
{
    data->player->sprite = sfSprite_create();
    data->player->name = "Valentin";
    data->player->texture =
    sfTexture_createFromFile("assets/character/sheet.png", NULL);
    sfSprite_setTexture(data->player->sprite, data->player->texture, sfTrue);
    data->player->rect = (sfIntRect){0, 0, 18, 20};
    sfSprite_setTextureRect(data->player->sprite, data->player->rect);
    data->player->pos = (sfVector2f){1830, 4350};
    sfSprite_setPosition(data->player->sprite, data->player->pos);
    sfSprite_setScale(data->player->sprite, (sfVector2f){3, 3});
    data->player->clock = sfClock_create();
    data->player->effect_clock = NULL;
    data->player->hp = 20;
    data->player->hp_cb = data->player->hp;
    data->player->max_hp = 20;
    data->player->gold = 0;
    data->player->lv = 1;
    data->player->xp = 0;
    data->player->karma = 0;
    init_player2(data);
}
