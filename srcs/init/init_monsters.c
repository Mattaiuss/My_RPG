/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_monsters
*/

#include "../../includes/rpg.h"
#include "../../includes/characters.h"

void init_monsters(data_t *data)
{
    data->enemies = malloc(sizeof(enemy_t *) * NB_MOBS);
    data->current_enemy = NULL;
    init_slime(data);
}
