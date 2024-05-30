/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_quests
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void init_quest6(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 6: A mysterious old man?");
    new->desc = strdup(DESC6);
    new->func = &quest6;
    new->next = NULL;
    push_back_quest(data->quest, new);
}

void init_quest7(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 7: The next step");
    new->desc = strdup(DESC7);
    new->func = &quest7;
    new->next = NULL;
    push_back_quest(data->quest, new);
}

void init_quest8(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 8: Let's XP!");
    new->desc = strdup(DESC8);
    new->func = &quest8;
    new->next = NULL;
    push_back_quest(data->quest, new);
}

void init_quest9(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 9: The end");
    new->desc = strdup(DESC9);
    new->func = &quest9;
    new->next = NULL;
    push_back_quest(data->quest, new);
}

void init_quest10(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 10: A new beginning");
    new->desc = strdup(DESC10);
    new->func = &quest10;
    new->next = NULL;
    push_back_quest(data->quest, new);
}
