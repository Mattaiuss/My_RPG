/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** quest_foncs
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void check_move(data_t *data)
{
    static int up = 0;
    static int down = 0;
    static int left = 0;
    static int right = 0;

    if (data->keys->up_pressed == 1)
        up = 1;
    if (data->keys->down_pressed == 1)
        down = 1;
    if (data->keys->left_pressed == 1)
        left = 1;
    if (data->keys->right_pressed == 1)
        right = 1;
    if (up == 1 && down == 1 && left == 1 && right == 1) {
        free(data->quest->title);
        free(data->quest->desc);
        data->quest = data->quest->next;
    }
}

void quest2(data_t *data)
{
    if (data->scene == PAUSE && data->prev_scene == GAME) {
        free(data->quest->title);
        free(data->quest->desc);
        data->quest = data->quest->next;
    }
}

void quest3(data_t *data)
{
    if (data->player->inventory->equip[0] != NULL)
        if (data->player->inventory->equip[0]->item->id == 0) {
            free(data->quest->title);
            free(data->quest->desc);
            data->quest = data->quest->next;
        }
    if (data->player->inventory->equip[1] != NULL)
        if (data->player->inventory->equip[1]->item->id == 0) {
            free(data->quest->title);
            free(data->quest->desc);
            data->quest = data->quest->next;
        }
}

void quest4(data_t *data)
{
    if (data->player->pos.x > data->zones[0]->pos.x &&
    data->player->pos.x < data->zones[0]->pos.x +
    data->zones[0]->size.x &&
    data->player->pos.y > data->zones[0]->pos.y &&
    data->player->pos.y < data->zones[0]->pos.y +
    data->zones[0]->size.y) {
        free(data->quest->title);
        free(data->quest->desc);
        data->quest = data->quest->next;
    }
}

void quest5(data_t *data)
{
    if (data->mob_killed > 2) {
        free(data->quest->title);
        free(data->quest->desc);
        data->quest = data->quest->next;
    }
    data->prev_scene = data->scene;
}
