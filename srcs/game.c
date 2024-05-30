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
    for (int i = 0; i < NB_NPC; i++)
        if (data->npcs[i]->pos.x != 0 && data->npcs[i]->pos.y != 0 &&
        i != DARIUS) {
            sfRenderWindow_drawSprite(data->window->window,
            data->npcs[i]->sprite, NULL);
        }
    if (data->npcs[DARIUS]->pos.y + 70 <= data->player->pos.y)
        sfRenderWindow_drawSprite(data->window->window,
        data->npcs[DARIUS]->sprite, NULL);
    sfRenderWindow_drawSprite(data->window->window,
    data->player->sprite, NULL);
    if (data->npcs[DARIUS]->pos.y + 70 > data->player->pos.y)
        sfRenderWindow_drawSprite(data->window->window,
        data->npcs[DARIUS]->sprite, NULL);
    sfRenderWindow_drawSprite(data->window->window,
    data->game->map_haut_sprite, NULL);
}

static void change_disp_quest(data_t *data)
{
    char buffer[256];

    if (data->quest->title[6] == '1') {
        sprintf(buffer, "%s%s", DESC1, data->keys->up == sfKeyZ ?
        "'ZQSD'." : "'WASD'.");
        data->quest->desc = strdup(buffer);
    }
    if (data->quest->title[6] == '5') {
        sprintf(buffer, "%s%d%s", DESC5, data->mob_killed, " / 3)");
        data->quest->desc = strdup(buffer);
    }
    if (data->quest->title[6] == '8') {
        sprintf(buffer, "%s%d%s", DESC8, data->mob_killed, " / 5)");
        data->quest->desc = strdup(buffer);
    }
}

void draw_quest(data_t *data)
{
    sfText *text = sfText_create();

    if (data->quest == NULL) {
        sfText_destroy(text);
        return;
    }
    change_disp_quest(data);
    text = create_text(data, (sfVector2f){data->player->pos.x + 180,
    data->player->pos.y - 260}, sfYellow, 20);
    sfText_setString(text, data->quest->title);
    sfRenderWindow_drawText(data->window->window, text, NULL);
    text = create_text(data, (sfVector2f){data->player->pos.x + 200,
    data->player->pos.y - 230}, sfWhite, 15);
    sfText_setString(text, data->quest->desc);
    sfRenderWindow_drawText(data->window->window, text, NULL);
    sfText_destroy(text);
}

static void game_loop(data_t *data)
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
        draw_quest(data);
        data->quest->func(data);
        if (data->prev_scene == DIALOGUE)
            data->prev_scene = GAME;
        sfRenderWindow_display(data->window->window);
        sfClock_restart(data->window->clock);
    }
}

static void reset_some_val_scene(data_t *data)
{
    if (data->scene == COMBAT) {
        data->combat->byakuya_used = 0;
        data->combat->rukia_used = 0;
        sfSleep(sfMilliseconds(100));
    }
    if (data->scene == DIALOGUE) {
        sfSprite_setScale(data->pause->action_sprite, (sfVector2f){0.8, 0.1});
    }
}

void shop(data_t *data)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->window->clock))
    > 1000 / 60) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        if (data->prev_scene == SHOP) {
            reset_view_temp(data);
            sfRenderWindow_setView(data->window->window,
            data->window->gameview);
            draw_sprite_game(data);
            sfRenderWindow_setView(data->window->window, data->window->view);
        } else
            draw_sprite_game(data);
        sfRenderWindow_display(data->window->window);
        sfClock_restart(data->window->clock);
    }
}

void game(data_t *data)
{
    while (data->scene == PAUSE)
        pause_wind(data);
    while (data->scene == SHOP)
        shop(data);
    reset_some_val_scene(data);
    while (data->scene == DIALOGUE)
        dialogue(data, NPC);
    while (data->scene == COMBAT)
        combat(data);
    while (data->scene == GAME)
        game_loop(data);
}
