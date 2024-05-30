/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_npc8to11
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"
#include "../../../includes/npcs.h"
#include "../../../includes/my.h"

void init_npc11(data_t *data)
{
    data->npcs[ELOWEN]->name = strdup("Elowen");
    data->npcs[ELOWEN]->id = ELOWEN;
    data->npcs[ELOWEN]->type = SIMP;
    data->npcs[ELOWEN]->quest_npc = sfFalse;
    data->npcs[ELOWEN]->nb_dialogues = 1;
    data->npcs[ELOWEN]->dial_file = malloc(sizeof(char *) *
    data->npcs[ELOWEN]->nb_dialogues);
    data->npcs[ELOWEN]->dial_file[0] = strdup("assets/dialogues/elowen1.txt");
    data->npcs[ELOWEN]->pos = (sfVector2f){3507, 4003};
    sfSprite_setPosition(data->npcs[ELOWEN]->sprite, data->npcs[ELOWEN]->pos);
}

void init_npc10(data_t *data)
{
    data->npcs[LOTHAR]->name = strdup("Lothar");
    data->npcs[LOTHAR]->id = LOTHAR;
    data->npcs[LOTHAR]->type = SIMP;
    data->npcs[LOTHAR]->quest_npc = sfTrue;
    data->npcs[LOTHAR]->nb_dialogues = 2;
    data->npcs[LOTHAR]->dial_file = malloc(sizeof(char *) *
    data->npcs[LOTHAR]->nb_dialogues);
    data->npcs[LOTHAR]->dial_file[0] = strdup("assets/dialogues/lothar1.txt");
    data->npcs[LOTHAR]->dial_file[1] = strdup("assets/dialogues/lothar2.txt");
    data->npcs[LOTHAR]->pos = (sfVector2f){5248, 2242};
    sfSprite_setPosition(data->npcs[LOTHAR]->sprite, data->npcs[LOTHAR]->pos);
}

void init_npc9(data_t *data)
{
    data->npcs[CEDRIC]->name = strdup("Cedric");
    data->npcs[CEDRIC]->id = CEDRIC;
    data->npcs[CEDRIC]->type = SIMP;
    data->npcs[CEDRIC]->quest_npc = sfFalse;
    data->npcs[CEDRIC]->nb_dialogues = 0;
    data->npcs[CEDRIC]->dial_file = NULL;
    data->npcs[CEDRIC]->pos = (sfVector2f){0, 0};
}

void init_npc8(data_t *data)
{
    data->npcs[THALIA]->name = strdup("Thalia");
    data->npcs[THALIA]->id = THALIA;
    data->npcs[THALIA]->type = SIMP;
    data->npcs[THALIA]->quest_npc = sfFalse;
    data->npcs[THALIA]->nb_dialogues = 0;
    data->npcs[THALIA]->dial_file = NULL;
    data->npcs[THALIA]->pos = (sfVector2f){0, 0};
}

void init_npc811(data_t *data)
{
    init_npc8(data);
    init_npc9(data);
    init_npc10(data);
    init_npc11(data);
}
