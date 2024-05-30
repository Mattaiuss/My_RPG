/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_characters
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

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
    if (data->ret == 1) {
        data->player->def = 15;
        data->player->atk = 15;
        data->quest_index = 0;
        data->mob_killed = 0;
    }
    data->player->clock = sfClock_create();
    data->player->effect_clock = NULL;
    data->player->hp_cb = data->player->hp;
    data->player->atk_cb = data->player->atk;
    data->player->def_cb = data->player->def;
    data->player->speed = 2;
    data->player->inventory = malloc(sizeof(inventory_t));
    data->player->inventory->nb_held_items = 0;
    data->player->isgm = sfFalse;
    data->player->nearnpc = sfFalse;
}

static int test_file(FILE *fd)
{
    if (fd == NULL) {
        write(2, "No save found\n", 14);
        return 1;
    }
    fseek(fd, 0, SEEK_END);
    if (ftell(fd) == 0) {
        write(2, "The save is empty\n", 18);
        return 1;
    }
    fseek(fd, 0, SEEK_SET);
    return 0;
}

int load_save(data_t *data)
{
    FILE *fd = fopen("saves/save.dat", "r");

    if (test_file(fd) == 1)
        return 1;
    fread(&data->player->pos, sizeof(sfVector2f), 1, fd);
    fread(&data->player->atk, sizeof(int), 1, fd);
    fread(&data->player->def, sizeof(int), 1, fd);
    fread(&data->player->hp, sizeof(int), 1, fd);
    fread(&data->player->lv, sizeof(int), 1, fd);
    fread(&data->player->max_hp, sizeof(int), 1, fd);
    fread(&data->player->xp, sizeof(int), 1, fd);
    fread(&data->player->gold, sizeof(int), 1, fd);
    fread(&data->player->karma, sizeof(int), 1, fd);
    fread(&data->quest_index, sizeof(int), 1, fd);
    fread(&data->mob_killed, sizeof(int), 1, fd);
    fclose(fd);
    write(1, "Save loaded\n", 12);
    return 0;
}

void init_player(data_t *data)
{
    data->ret = load_save(data);
    if (data->ret == 1) {
        data->player->pos = (sfVector2f){1956, 4014};
        data->player->hp = 20;
        data->player->lv = 1;
        data->player->max_hp = 20;
        data->player->gold = 0;
        data->player->xp = 0;
        data->player->karma = 0;
    }
    data->player->sprite = sfSprite_create();
    data->player->name = "Valentin";
    data->player->texture =
    sfTexture_createFromFile("assets/character/sheet.png", NULL);
    sfSprite_setTexture(data->player->sprite, data->player->texture, sfTrue);
    data->player->rect = (sfIntRect){0, 0, 18, 20};
    sfSprite_setTextureRect(data->player->sprite, data->player->rect);
    sfSprite_setPosition(data->player->sprite, data->player->pos);
    sfSprite_setScale(data->player->sprite, (sfVector2f){3, 3});
    init_player2(data);
}
