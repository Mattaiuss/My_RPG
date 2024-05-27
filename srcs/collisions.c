/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** collisions
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

sfBool check_collision(data_t *data, int x, int y)
{
    int pos_x = (data->player->pos.x + x) / 32;
    int pos_y = (data->player->pos.y + y +
    sfSprite_getGlobalBounds(data->player->sprite).height) / 32;
    int pos_x2 = (data->player->pos.x + x +
    sfSprite_getGlobalBounds(data->player->sprite).width) / 32;

    if (data->player->isgm == sfTrue)
        return (sfTrue);
    for (int i = 0; data->collision_map[i] != -1; i += 2) {
        if (data->collision_map[i] == pos_x &&
        data->collision_map[i + 1] == pos_y)
            return (sfFalse);
    }
    for (int i = 0; data->collision_map[i] != -1; i += 2) {
        if (data->collision_map[i] == pos_x2 &&
        data->collision_map[i + 1] == pos_y)
            return (sfFalse);
    }
    check_spawn_enemy(data);
    return (sfTrue);
}
