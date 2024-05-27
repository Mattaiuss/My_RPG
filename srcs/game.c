/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** game
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void restart_music(data_t *data)
{
    if (data->scene == MENU && data->prev_scene == PAUSE) {
        sfMusic_stop(data->music);
        sfMusic_destroy(data->music);
        data->music = sfMusic_createFromFile("assets/musics/menu.ogg");
        sfMusic_play(data->music);
        sfMusic_setLoop(data->music, sfTrue);
    }
    if (data->prev_scene == MENU && data->scene == GAME) {
        sfMusic_stop(data->music);
        sfMusic_destroy(data->music);
        data->music = sfMusic_createFromFile("assets/musics/village.ogg");
        sfMusic_play(data->music);
        sfMusic_setLoop(data->music, sfTrue);
    }
}

void draw_sprite_game(data_t *data)
{
    sfRenderWindow_drawSprite(data->window->window,
    data->game->map_bas_sprite, NULL);
    sfRenderWindow_drawSprite(data->window->window,
    data->player->sprite, NULL);
    sfRenderWindow_drawSprite(data->window->window,
    data->game->map_haut_sprite, NULL);
}

void game_loop(data_t *data)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->window->clock))
    > 1000 / 60) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        sfView_setCenter(data->window->gameview, data->player->pos);
        sfView_setSize(data->window->gameview, (sfVector2f){WIDTH, HEIGHT});
        sfView_zoom(data->window->gameview, 0.6);
        check_effect_clock(data);
        data->window->view_pos = sfView_getCenter(data->window->gameview);
        sfRenderWindow_setView(data->window->window, data->window->gameview);
        draw_sprite_game(data);
        move_map(data);
        is_p_in_zone(data);
        sfRenderWindow_display(data->window->window);
        sfClock_restart(data->window->clock);
    }
}

void reset_val_spe_weapon(data_t *data)
{
    if (data->scene == COMBAT) {
        data->combat->byakuya_used = 0;
        data->combat->rukia_used = 0;
        sfSleep(sfMilliseconds(100));
    }
}

void game(data_t *data)
{
    while (data->scene == PAUSE)
        pause_wind(data);
    reset_val_spe_weapon(data);
    while (data->scene == COMBAT)
        combat(data);
    while (data->scene == GAME)
        game_loop(data);
}
