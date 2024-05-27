/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_attacks
*/

#include "../../../includes/rpg.h"
#include "../../../includes/my.h"

attack_t *copy_attack(attack_t *attack, char *path)
{
    attack->pos = (sfVector2f){0, 0};
    attack->dir = (sfVector2f){0, 0};
    attack->og_pos = (sfVector2f){0, 0};
    attack->sprite = sfSprite_create();
    attack->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(attack->sprite, attack->texture, sfTrue);
    return attack;
}
