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
    if (strcmp(path, "assets/attacks/stick.png") == 0)
        sfSprite_setScale(attack->sprite, (sfVector2f){0.05, 0.05});
    if (strcmp(path, "assets/attacks/bone.png") == 0)
        sfSprite_setScale(attack->sprite, (sfVector2f){0.3, 0.5});
    if (strcmp(path, "assets/attacks/spear.png") == 0)
        sfSprite_setScale(attack->sprite, (sfVector2f){0.1, 0.1});
    if (strcmp(path, "assets/attacks/spear2.png") == 0)
        sfSprite_setScale(attack->sprite, (sfVector2f){0.1, 0.1});
    if (strcmp(path, "assets/attacks/spear3.png") == 0)
        sfSprite_setScale(attack->sprite, (sfVector2f){0.1, 0.1});
    return attack;
}
