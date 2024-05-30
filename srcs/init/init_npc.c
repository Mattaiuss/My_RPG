/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_npc
*/

#include "../../includes/rpg.h"
#include "../../includes/characters.h"
#include "../../includes/npcs.h"
#include "../../includes/my.h"

void init_npc(data_t *data)
{
    data->npcs = malloc(sizeof(npc_t *) * NB_NPC);
    data->current_npc = NULL;
    for (int i = 0; i < NB_NPC; i++) {
        data->npcs[i] = malloc(sizeof(npc_t));
        data->npcs[i]->sprite = sfSprite_create();
        data->npcs[i]->texture = sfTexture_createFromFile
        (my_super_str_cat_int("assets/npcs/npc", i, ".png"), NULL);
        sfSprite_setTexture(data->npcs[i]->sprite, data->npcs[i]->texture,
        sfTrue);
        sfSprite_setScale(data->npcs[i]->sprite, (sfVector2f){1.5, 1.5});
    }
    init_npc03(data);
    init_npc47(data);
    init_npc811(data);
    init_npc1215(data);
    init_npc1617(data);
    data->current_npc = NULL;
}
