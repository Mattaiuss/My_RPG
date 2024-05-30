/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_npc16to17
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"
#include "../../../includes/npcs.h"
#include "../../../includes/my.h"

void init_npc17(data_t *data)
{
    data->npcs[DARIUS]->name = strdup("Darius");
    data->npcs[DARIUS]->id = DARIUS;
    data->npcs[DARIUS]->type = SIMP;
    data->npcs[DARIUS]->quest_npc = sfTrue;
    data->npcs[DARIUS]->nb_dialogues = 2;
    data->npcs[DARIUS]->dial_file = malloc(sizeof(char *) *
    data->npcs[DARIUS]->nb_dialogues);
    data->npcs[DARIUS]->dial_file[0] = strdup("assets/dialogues/darius1.txt");
    data->npcs[DARIUS]->dial_file[1] = strdup("assets/dialogues/darius2.txt");
    data->npcs[DARIUS]->pos = (sfVector2f){11140, 4086};
    sfSprite_setPosition(data->npcs[DARIUS]->sprite, data->npcs[DARIUS]->pos);
}

void init_npc16(data_t *data)
{
    data->npcs[GARETH]->name = strdup("Gareth");
    data->npcs[GARETH]->id = GARETH;
    data->npcs[GARETH]->type = SIMP;
    data->npcs[GARETH]->quest_npc = sfFalse;
    data->npcs[GARETH]->nb_dialogues = 0;
    data->npcs[GARETH]->dial_file = NULL;
    data->npcs[GARETH]->pos = (sfVector2f){0, 0};
}

void init_npc1617(data_t *data)
{
    init_npc16(data);
    init_npc17(data);
}
