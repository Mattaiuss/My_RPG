/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** pause
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"
#include <string.h>

void draw_pause(data_t *data)
{
    data->pause->pos = (sfVector2f){data->window->view_pos.x -
    sfRenderWindow_getSize(data->window->window).x / 4,
    data->window->view_pos.y - sfRenderWindow_getSize(data->window->window).y
    / 4 + 30};
    sfSprite_setPosition(data->pause->pause_menu_sprite, data->pause->pos);
    sfRenderWindow_drawSprite(data->window->window,
    data->pause->pause_menu_sprite, NULL);
    data->pause->text = sfText_create();
    sfText_setFont(data->pause->text, data->font);
    sfText_setCharacterSize(data->pause->text, 50);
    sfText_setString(data->pause->text, "PAUSE");
    sfText_setPosition(data->pause->text, (sfVector2f){data->pause->pos.x +
    295, data->pause->pos.y - 60});
    sfRenderWindow_drawText(data->window->window, data->pause->text, NULL);
    draw_pause_texts(data);
}

void pause_wind(data_t *data)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->window->clock))
    > 1000 / 60) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        move_index(data);
        if (data->prev_scene == SETTINGS) {
            reset_view_temp(data);
            sfRenderWindow_setView(data->window->window,
            data->window->gameview);
            draw_sprite_game(data);
            sfRenderWindow_setView(data->window->window, data->window->view);
        } else
            draw_sprite_game(data);
        draw_pause(data);
        draw_quest(data);
        data->quest->func(data);
        sfRenderWindow_display(data->window->window);
        sfClock_restart(data->window->clock);
    }
}
