/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_npc0to3
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"
#include "../../../includes/npcs.h"
#include "../../../includes/my.h"

void init_npc3(data_t *data)
{
    data->npcs[BALIAN]->name = strdup("Balian");
    data->npcs[BALIAN]->id = BALIAN;
    data->npcs[BALIAN]->type = SIMP;
    data->npcs[BALIAN]->quest_npc = sfFalse;
    data->npcs[BALIAN]->nb_dialogues = 0;
    data->npcs[BALIAN]->dial_file = NULL;
    data->npcs[BALIAN]->pos = (sfVector2f){0, 0};
}

void init_npc2(data_t *data)
{
    data->npcs[ASTRID]->name = strdup("Astrid");
    data->npcs[ASTRID]->id = ASTRID;
    data->npcs[ASTRID]->type = SIMP;
    data->npcs[ASTRID]->quest_npc = sfFalse;
    data->npcs[ASTRID]->nb_dialogues = 0;
    data->npcs[ASTRID]->dial_file = NULL;
    data->npcs[ASTRID]->pos = (sfVector2f){0, 0};
}

void init_npc1(data_t *data)
{
    data->npcs[THORNE]->name = strdup("Thorne");
    data->npcs[THORNE]->id = THORNE;
    data->npcs[THORNE]->type = SIMP;
    data->npcs[THORNE]->quest_npc = sfFalse;
    data->npcs[THORNE]->nb_dialogues = 0;
    data->npcs[THORNE]->dial_file = NULL;
    data->npcs[THORNE]->pos = (sfVector2f){0, 0};
}

void init_npc0(data_t *data)
{
    data->npcs[ELYSANDE]->name = strdup("Elysande");
    data->npcs[ELYSANDE]->id = ELYSANDE;
    data->npcs[ELYSANDE]->type = SIMP;
    data->npcs[ELYSANDE]->quest_npc = sfFalse;
    data->npcs[ELYSANDE]->nb_dialogues = 0;
    data->npcs[ELYSANDE]->dial_file = NULL;
    data->npcs[ELYSANDE]->pos = (sfVector2f){0, 0};
}

void init_npc03(data_t *data)
{
    init_npc0(data);
    init_npc1(data);
    init_npc2(data);
    init_npc3(data);
}
