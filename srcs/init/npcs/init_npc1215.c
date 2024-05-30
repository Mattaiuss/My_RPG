/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_npc12to15
*/

#include "../../../includes/rpg.h"
#include "../../../includes/characters.h"
#include "../../../includes/npcs.h"
#include "../../../includes/my.h"

void init_npc15(data_t *data)
{
    data->npcs[REDERIC]->name = strdup("Rederic");
    data->npcs[REDERIC]->id = REDERIC;
    data->npcs[REDERIC]->type = SIMP;
    data->npcs[REDERIC]->quest_npc = sfFalse;
    data->npcs[REDERIC]->nb_dialogues = 1;
    data->npcs[REDERIC]->dial_file = malloc(sizeof(char *) *
    data->npcs[REDERIC]->nb_dialogues);
    data->npcs[REDERIC]->dial_file[0] =
    strdup("assets/dialogues/rederic1.txt");
    data->npcs[REDERIC]->pos = (sfVector2f){2434, 4002};
    sfSprite_setPosition(data->npcs[REDERIC]->sprite,
    data->npcs[REDERIC]->pos);
}

void init_npc14(data_t *data)
{
    data->npcs[SELENA]->name = strdup("Selena");
    data->npcs[SELENA]->id = SELENA;
    data->npcs[SELENA]->type = SIMP;
    data->npcs[SELENA]->quest_npc = sfFalse;
    data->npcs[SELENA]->nb_dialogues = 0;
    data->npcs[SELENA]->dial_file = NULL;
    data->npcs[SELENA]->pos = (sfVector2f){0, 0};
}

void init_npc13(data_t *data)
{
    data->npcs[ISOLDE]->name = strdup("Isolde");
    data->npcs[ISOLDE]->id = ISOLDE;
    data->npcs[ISOLDE]->type = SIMP;
    data->npcs[ISOLDE]->quest_npc = sfFalse;
    data->npcs[ISOLDE]->nb_dialogues = 0;
    data->npcs[ISOLDE]->dial_file = NULL;
    data->npcs[ISOLDE]->pos = (sfVector2f){0, 0};
}

void init_npc12(data_t *data)
{
    data->npcs[NYMERIA]->name = strdup("Nymeria");
    data->npcs[NYMERIA]->id = NYMERIA;
    data->npcs[NYMERIA]->type = SIMP;
    data->npcs[NYMERIA]->quest_npc = sfFalse;
    data->npcs[NYMERIA]->nb_dialogues = 0;
    data->npcs[NYMERIA]->dial_file = NULL;
    data->npcs[NYMERIA]->pos = (sfVector2f){0, 0};
}

void init_npc1215(data_t *data)
{
    init_npc12(data);
    init_npc13(data);
    init_npc14(data);
    init_npc15(data);
}
