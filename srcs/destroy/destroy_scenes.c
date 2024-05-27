/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** destroy_scenes
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void destroy_param(param_t *param)
{
    sfSprite_destroy(param->bg_sprite);
    sfTexture_destroy(param->bg_texture);
    for (int i = 0; i < param->nb_buttons; i++) {
        sfSprite_destroy(param->buttons[i]->sprite);
        sfTexture_destroy(param->buttons[i]->texture);
        free(param->buttons[i]);
    }
    free(param->buttons);
    free(param);
}

void destroy_menu(menu_t *menu)
{
    for (int i = 0; i < menu->nb_buttons; i++) {
        sfSprite_destroy(menu->buttons[i]->sprite);
        sfTexture_destroy(menu->buttons[i]->texture);
        free(menu->buttons[i]);
    }
    sfSprite_destroy(menu->bg_sprite);
    sfTexture_destroy(menu->background);
    free(menu->buttons);
    free(menu);
}

void destroy_game(game_t *game)
{
    sfSprite_destroy(game->map_bas_sprite);
    sfTexture_destroy(game->map_bas_text);
    sfSprite_destroy(game->map_haut_sprite);
    sfTexture_destroy(game->map_haut_text);
    free(game);
}

void destroy_pause(pause_t *pause)
{
    sfTexture_destroy(pause->pause_menu_text);
    sfSprite_destroy(pause->pause_menu_sprite);
    sfTexture_destroy(pause->action_text);
    sfSprite_destroy(pause->action_sprite);
    free(pause);
}

void destroy_combat(combat_t *combat)
{
    sfClock_destroy(combat->animation);
    sfClock_destroy(combat->invul);
    sfSprite_destroy(combat->f_square);
    sfTexture_destroy(combat->f_texture);
    sfSprite_destroy(combat->a_square);
    sfTexture_destroy(combat->a_texture);
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(combat->buttons[i]->sprite);
        sfTexture_destroy(combat->buttons[i]->texture);
        free(combat->buttons[i]);
    }
    sfClock_destroy(combat->act_clock);
    free(combat->buttons);
    free(combat);
}
