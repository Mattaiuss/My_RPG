/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_quests
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void push_back_quest(quest_t *head, quest_t *new)
{
    quest_t *tmp = head;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

static void init_quest1(data_t *data)
{
    char buffer[256];

    data->quest->title = strdup("Quest 1: First steps");
    sprintf(buffer, "%s%s", DESC1, data->keys->up == sfKeyZ ? "ZQSD" : "WASD");
    data->quest->desc = strdup(buffer);
    data->quest->func = &check_move;
    data->quest->next = NULL;
}

static void init_quest2(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 2: Pause menu");
    new->desc = strdup(DESC2);
    new->func = &quest2;
    new->next = NULL;
    push_back_quest(data->quest, new);
}

static void init_quest3(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 3: Boost your stats!");
    new->desc = strdup(DESC3);
    new->func = &quest3;
    new->next = NULL;
    push_back_quest(data->quest, new);
}

static void init_quest4(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 4: Start your journey");
    new->desc = strdup(DESC4);
    new->func = &quest4;
    new->next = NULL;
    push_back_quest(data->quest, new);
}

void init_quest5(data_t *data)
{
    quest_t *new = malloc(sizeof(quest_t));

    new->title = strdup("Quest 5: Let's fight!");
    new->desc = strdup(DESC5);
    new->func = &quest5;
    new->next = NULL;
    push_back_quest(data->quest, new);
}

void skip_quest(data_t *data)
{
    for (int i = 0; i < data->quest_index - 1; i++)
        data->quest = data->quest->next;
}

void init_quest(data_t *data)
{
    data->quest = malloc(sizeof(quest_t));
    init_quest1(data);
    init_quest2(data);
    init_quest3(data);
    init_quest4(data);
    init_quest5(data);
    init_quest6(data);
    init_quest7(data);
    init_quest8(data);
    init_quest9(data);
    init_quest10(data);
    skip_quest(data);
}
