/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** destroy_all
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

static void destroy_window(window_t *window)
{
    sfClock_destroy(window->clock);
    sfView_destroy(window->view);
    sfView_destroy(window->gameview);
    sfSprite_destroy(window->mouse->sprite);
    sfTexture_destroy(window->mouse->texture);
    free(window->mouse);
}

static void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->clock);
    sfClock_destroy(player->effect_clock);
    free(player);
}

void destroy_soul(soul_t *soul)
{
    sfSprite_destroy(soul->sprite);
    sfTexture_destroy(soul->texture);
    free(soul);
}

void destroy_items(item_t *item)
{
    sfSprite_destroy(item->sprite);
    sfTexture_destroy(item->texture);
    free(item);
}

void destroy_zones(zone_t **zones)
{
    for (int i = 0; i < 2; i++) {
        sfRectangleShape_destroy(zones[i]->shape);
        sfSprite_destroy(zones[i]->bg);
        sfTexture_destroy(zones[i]->bg_text);
        free(zones[i]);
    }
    free(zones);
}

void destroy_enemies(data_t *data)
{
    sfTexture_destroy(data->enemies[SLIME]->texture);
    sfSprite_destroy(data->enemies[SLIME]->sprite);
    for (int i = 0; i < data->enemies[SLIME]->nb_waves; i++) {
        for (int j = 0; j < data->enemies[SLIME]->waves[i]->nb_attacks; j++) {
            sfTexture_destroy(
                data->enemies[SLIME]->waves[i]->attacks[j]->texture);
            sfSprite_destroy(
                data->enemies[SLIME]->waves[i]->attacks[j]->sprite);
            free(data->enemies[SLIME]->waves[i]->attacks[j]);
        }
        free(data->enemies[SLIME]->waves[i]->attacks);
        sfClock_destroy(data->enemies[SLIME]->waves[i]->clock);
        free(data->enemies[SLIME]->waves[i]);
    }
    free(data->enemies[SLIME]->waves);
    free(data->enemies[SLIME]);
    free(data->enemies);
}

void destroy_all(data_t *data)
{
    destroy_window(data->window);
    destroy_param(data->param[0]);
    destroy_menu(data->menu);
    destroy_game(data->game);
    destroy_pause(data->pause);
    destroy_combat(data->combat);
    free(data->keys);
    sfFont_destroy(data->font);
    sfMusic_destroy(data->music);
    destroy_player(data->player);
    destroy_soul(data->soul);
    destroy_items(data->item);
    destroy_zones(data->zones);
    destroy_enemies(data);
    sfMusic_destroy(data->combat_music);
    free(data);
}
