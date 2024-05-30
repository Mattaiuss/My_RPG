/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** quest_foncs2
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void quest9(data_t *data)
{
    static int check = 0;

    if (data->current_npc != NULL)
        if (data->current_npc->id == 17 &&
        data->keys->interact_pressed == sfTrue) {
            check = 1;
        }
    if (check == 1 && data->prev_scene == DIALOGUE) {
        data->zones[2]->spawn_rate = 1;
        data->zones[2]->nb_mobs = 1;
        init_combat(data);
    }
    if (data->mob_killed == 1) {
        check = 0;
        free(data->quest->title);
        free(data->quest->desc);
        data->quest = data->quest->next;
    }
}

void quest10(data_t *data)
{
    (void)data;
    return;
}
