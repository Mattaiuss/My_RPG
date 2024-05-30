/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** movements
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void move_rect(player_t *player, int min, int max)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(player->clock))
    > 1000 / 10) {
        player->rect.left += 18;
        if (player->rect.left < min)
            player->rect.left = min;
        if (player->rect.left > max)
            player->rect.left = min;
        sfClock_restart(player->clock);
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void is_not_moving(data_t *data)
{
    if (data->keys->up_pressed == sfTrue || data->keys->down_pressed == sfTrue
    || data->keys->left_pressed == sfTrue || data->keys->right_pressed ==
    sfTrue) {
        return;
    }
    while (data->player->rect.left != 0 && data->player->rect.left != 18 * 4 &&
    data->player->rect.left != 18 * 8 && data->player->rect.left != 18 * 12) {
        data->player->rect.left -= 18;
        sfSprite_setTextureRect(data->player->sprite, data->player->rect);
    }
    return;
}

static void check_movements(data_t *data, float speed)
{
    if (data->keys->up_pressed) {
        move_rect(data->player, 18 * 8, 18 * 11);
        if (check_collision(data, 0, -speed) == sfTrue)
            data->player->pos.y -= speed;
    }
    if (data->keys->down_pressed) {
        move_rect(data->player, 0, 18 * 3);
        if (check_collision(data, 0, speed) == sfTrue)
            data->player->pos.y += speed;
    }
    if (data->keys->left_pressed) {
        move_rect(data->player, 18 * 12, 18 * 15);
        if (check_collision(data, -speed, 0) == sfTrue)
            data->player->pos.x -= speed;
    }
    if (data->keys->right_pressed) {
        move_rect(data->player, 18 * 4, 18 * 7);
        if (check_collision(data, speed, 0) == sfTrue)
            data->player->pos.x += speed;
    }
}

void check_near_npc(data_t *data)
{
    float dx = 0;
    float dy = 0;
    float distance_squared = 0;

    for (int i = 0; i < NB_NPC; i++) {
        dx = data->npcs[i]->pos.x - data->player->pos.x;
        dy = data->npcs[i]->pos.y - data->player->pos.y;
        distance_squared = dx * dx + dy * dy;
        if (distance_squared < 100 * 100) {
            data->current_npc = data->npcs[i];
            data->player->nearnpc = sfTrue;
            break;
        }
        data->current_npc = NULL;
        data->player->nearnpc = sfFalse;
    }
    if (data->player->nearnpc == sfTrue)
        if (data->keys->interact_pressed == sfTrue)
            data->scene = DIALOGUE;
}

void move_map(data_t *data)
{
    int speed = data->keys->shift_pressed ? data->player->speed * 2 :
        data->player->speed;
    int diagonal_speed = speed / 1.214;

    if (data->player->isgm == sfTrue) {
        speed = 12;
        diagonal_speed = 8;
    }
    if (data->keys->up_pressed && (data->keys->left_pressed ||
    data->keys->right_pressed))
        speed = diagonal_speed;
    if (data->keys->down_pressed && (data->keys->left_pressed ||
    data->keys->right_pressed))
        speed = diagonal_speed;
    check_movements(data, speed);
    is_not_moving(data);
    sfSprite_setPosition(data->player->sprite, data->player->pos);
    check_near_npc(data);
}
