/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_npc4to7
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"
#include "../../../includes/npcs.h"
#include "../../../includes/my.h"

void init_npc7(data_t *data)
{
    data->npcs[ALARIC]->name = strdup("Alaric");
    data->npcs[ALARIC]->id = ALARIC;
    data->npcs[ALARIC]->type = SIMP;
    data->npcs[ALARIC]->quest_npc = sfFalse;
    data->npcs[ALARIC]->nb_dialogues = 0;
    data->npcs[ALARIC]->dial_file = NULL;
    data->npcs[ALARIC]->pos = (sfVector2f){0, 0};
}

void init_npc6(data_t *data)
{
    data->npcs[GRIMBOK]->name = strdup("Grimbok");
    data->npcs[GRIMBOK]->id = GRIMBOK;
    data->npcs[GRIMBOK]->type = SIMP;
    data->npcs[GRIMBOK]->quest_npc = sfFalse;
    data->npcs[GRIMBOK]->nb_dialogues = 0;
    data->npcs[GRIMBOK]->dial_file = NULL;
    data->npcs[GRIMBOK]->pos = (sfVector2f){0, 0};
}

void init_npc5(data_t *data)
{
    data->npcs[LYANNA]->name = strdup("Lyanna");
    data->npcs[LYANNA]->id = LYANNA;
    data->npcs[LYANNA]->type = SIMP;
    data->npcs[LYANNA]->quest_npc = sfFalse;
    data->npcs[LYANNA]->nb_dialogues = 0;
    data->npcs[LYANNA]->dial_file = NULL;
    data->npcs[LYANNA]->pos = (sfVector2f){0, 0};
}

void init_npc4(data_t *data)
{
    data->npcs[MORGANE]->name = strdup("Morgane");
    data->npcs[MORGANE]->id = MORGANE;
    data->npcs[MORGANE]->type = SIMP;
    data->npcs[MORGANE]->quest_npc = sfFalse;
    data->npcs[MORGANE]->nb_dialogues = 0;
    data->npcs[MORGANE]->dial_file = NULL;
    data->npcs[MORGANE]->pos = (sfVector2f){0, 0};
}

void init_npc47(data_t *data)
{
    init_npc4(data);
    init_npc5(data);
    init_npc6(data);
    init_npc7(data);
}
