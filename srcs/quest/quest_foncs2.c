/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** quest_foncs2
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

int search_first_place(int size, data_t *data)
{
    for (int i = 0; i < size; i++) {
        if (data->player->inventory->invento[i] == NULL)
            return i;
    }
    return -1;
}

void add_new_item(data_t *data, int place, int id)
{
    if (place == -1)
        return;
    data->player->inventory->invento[place] = malloc(sizeof(box_t));
    data->player->inventory->invento[place]->shape = sfRectangleShape_create();
    data->player->inventory->invento[place]->pos = (sfVector2f){0, 0};
    data->player->inventory->invento[place]->size = (sfVector2f){0, 0};
    data->player->inventory->invento[place]->texture = NULL;
    data->player->inventory->invento[place]->sprite = NULL;
    set_item_box(data, data->player->inventory->invento[place], id);
}

void quest6(data_t *data)
{
    static int check = 0;

    if (data->current_npc != NULL)
        if (data->current_npc->id == 10 &&
        data->keys->interact_pressed == sfTrue) {
            check = 1;
        }
    if (check == 1 && data->prev_scene == DIALOGUE) {
        free(data->quest->title);
        free(data->quest->desc);
        data->quest = data->quest->next;
        add_new_item(data, search_first_place(10, data), 2);
    }
}

void quest7(data_t *data)
{
    if (data->player->pos.x > data->zones[1]->pos.x &&
    data->player->pos.x < data->zones[1]->pos.x +
    data->zones[1]->size.x &&
    data->player->pos.y > data->zones[1]->pos.y &&
    data->player->pos.y < data->zones[1]->pos.y +
    data->zones[1]->size.y) {
        free(data->quest->title);
        free(data->quest->desc);
        data->quest = data->quest->next;
        data->mob_killed = 0;
    }
}

void quest8(data_t *data)
{
    if (data->mob_killed > 4) {
        free(data->quest->title);
        free(data->quest->desc);
        data->quest = data->quest->next;
    }
}
