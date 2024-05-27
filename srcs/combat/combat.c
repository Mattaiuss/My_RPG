/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** combat
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void move_soul(data_t *data)
{
    if (data->keys->up_pressed == sfTrue && (data->player->pos.y -
    data->soul->pos.y) < 190)
        data->soul->pos.y -= 5;
    if (data->keys->down_pressed == sfTrue && (data->soul->pos.y -
    data->player->pos.y) < -15)
        data->soul->pos.y += 5;
    if (data->keys->left_pressed == sfTrue && (data->player->pos.x -
    data->soul->pos.x) < 86)
        data->soul->pos.x -= 5;
    if (data->keys->right_pressed == sfTrue && (data) && (data->soul->pos.x -
    data->player->pos.x) < 84)
        data->soul->pos.x += 5;
    sfSprite_setPosition(data->soul->sprite, data->soul->pos);
}

static void move_fight_index(data_t *data)
{
    if (data->keys->interact_pressed == sfTrue)
        do_action(data);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->combat->act_clock))
    < 130)
        return;
    if (data->keys->right_pressed == sfTrue)
        data->combat->index_button++;
    if (data->keys->left_pressed == sfTrue)
        data->combat->index_button--;
    if (data->combat->index_button < 0)
        data->combat->index_button = 3;
    if (data->combat->index_button > 3)
        data->combat->index_button = 0;
    sfClock_restart(data->combat->act_clock);
}

static void disp_fight_buttons(data_t *data)
{
    sfIntRect rect = {0, 0, 110, 42};

    move_fight_index(data);
    for (int i = 0; i < 4; i++)
        sfSprite_setTextureRect(data->combat->buttons[i]->sprite, rect);
    for (int i = 0; i < 4; i++) {
        if (i == data->combat->index_button)
            sfSprite_setTextureRect(data->combat->buttons[i]->sprite,
            (sfIntRect){110, 0, 110, 42});
        sfRenderWindow_drawSprite(data->window->window,
        data->combat->buttons[i]->sprite, NULL);
    }
}

void disp_act(data_t *data)
{
    sfSprite_setPosition(data->combat->a_square,
    (sfVector2f){data->player->pos.x - 450, data->player->pos.y - 250});
    sfRenderWindow_drawSprite(data->window->window, data->combat->a_square,
    NULL);
    disp_fight_buttons(data);
}

static void is_soul_touched(data_t *data)
{
    sfFloatRect soul_rect = sfSprite_getGlobalBounds(data->soul->sprite);
    sfFloatRect atk_rect;

    for (int i = 0; i < data->combat->current_wave->nb_attacks; i++) {
        atk_rect = sfSprite_getGlobalBounds(
            data->combat->current_wave->attacks[i]->sprite);
        if (sfFloatRect_intersects(&soul_rect, &atk_rect, NULL) == sfTrue) {
            data->player->hp = DAMAGE_TAKEN;
            data->combat->status = 0;
        }
    }
    if (data->player->hp <= 0)
        data->scene = GAME_OVER;
}

static void disp_attacks(data_t *data)
{
    attack_t *atk;

    is_soul_touched(data);
    for (int i = 0; i < data->combat->current_wave->nb_attacks; i ++) {
        atk = data->combat->current_wave->attacks[i];
        sfRenderWindow_drawSprite(data->window->window, atk->sprite, NULL);
        atk->pos.x += atk->dir.x;
        atk->pos.y += atk->dir.y;
        sfSprite_setPosition(atk->sprite, atk->pos);
    }
}

void disp_combat(data_t *data)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->combat->animation))
    >= data->combat->current_wave->time.microseconds / 1000) {
        data->combat->status = 0;
        data->soul->pos = (sfVector2f){data->player->pos.x - 5,
        data->player->pos.y - 100};
    }
    sfSprite_setPosition(data->combat->f_square,
    (sfVector2f){data->player->pos.x - 100, data->player->pos.y - 200});
    sfRenderWindow_drawSprite(data->window->window, data->combat->f_square,
    NULL);
    move_soul(data);
    disp_attacks(data);
    sfRenderWindow_drawSprite(data->window->window, data->soul->sprite, NULL);
}

void combat_loop(data_t *data)
{
    sfRenderWindow_clear(data->window->window, sfBlack);
    manage_events(data);
    sfRenderWindow_drawSprite(data->window->window, data->current_zone->bg,
    NULL);
    sfRenderWindow_drawSprite(data->window->window,
    data->current_enemy->sprite, NULL);
    if (data->combat->status == 0)
        disp_act(data);
    if (data->combat->status == 1)
        disp_combat(data);
    if (data->current_enemy != NULL)
        disp_additionnal(data);
    sfRenderWindow_display(data->window->window);
    sfClock_restart(data->window->clock);
}

void combat(data_t *data)
{
    data->player->pos = sfSprite_getPosition(data->player->sprite);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->window->clock))
    > 1000 / 60) {
        combat_loop(data);
    }
}
