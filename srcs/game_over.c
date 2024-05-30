/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** game_over
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void disp_and_destroy(data_t *data, sfText *go, sfText *replay, sfText *quit)
{
    sfRenderWindow_drawText(data->window->window, go, NULL);
    sfRenderWindow_drawText(data->window->window, replay, NULL);
    sfRenderWindow_drawText(data->window->window, quit, NULL);
    sfText_destroy(go);
    sfText_destroy(replay);
    sfText_destroy(quit);
}

void set_color(sfText *go, int i, sfText *replay, sfText *quit)
{
    sfText_setColor(go, sfColor_fromRGBA(255, 0, 0, i * 0.25));
    sfText_setColor(replay, sfColor_fromRGBA(255, 255, 255, 255));
    sfText_setColor(quit, sfColor_fromRGBA(255, 255, 255, 255));
}

void disp_texts(data_t *data, int i)
{
    sfText *go = sfText_create();
    sfText *replay = sfText_create();
    sfText *quit = sfText_create();
    sfVector2f pos = {data->player->pos.x, data->player->pos.y};

    sfText_setString(go, "Don't give up!");
    sfText_setString(replay, "Press E to replay.");
    sfText_setString(quit, "Press Escape to quit.");
    sfText_setFont(go, data->font);
    sfText_setFont(replay, data->font);
    sfText_setFont(quit, data->font);
    set_color(go, i, replay, quit);
    sfText_setCharacterSize(go, 50);
    sfText_setCharacterSize(replay, 30);
    sfText_setCharacterSize(quit, 25);
    sfText_setPosition(go, (sfVector2f){pos.x - 160, pos.y - 100});
    sfText_setPosition(replay, (sfVector2f){pos.x - 140, pos.y + 50});
    sfText_setPosition(quit, (sfVector2f){pos.x - 110, pos.y + 100});
    disp_and_destroy(data, go, replay, quit);
}

static void check_binds(data_t *data)
{
    if (data->keys->interact_pressed == sfTrue) {
        data->scene = GAME;
        data->player->hp = data->player->max_hp;
    }
    if (data->keys->is_escape_pressed == sfTrue) {
        data->scene = -1;
    }
}

void display_go(data_t *data)
{
    int i = 0;

    while (data->scene == GAME_OVER) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        disp_texts(data, i);
        check_binds(data);
        sfRenderWindow_display(data->window->window);
        i ++;
    }
}
