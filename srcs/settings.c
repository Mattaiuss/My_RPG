/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** settings
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

static void check_is_hover(data_t *data, int i)
{
    if (is_hover(data->param[0]->buttons[i], data) == sfTrue) {
        sfSprite_setTextureRect(data->param[0]->buttons[i]->sprite,
        data->param[0]->buttons[i]->rect[1]);
        if (data->keys->left_click == sfTrue) {
            data->param[0]->buttons[i]->callback(data);
            data->keys->left_click = sfFalse;
        }
    } else {
        sfSprite_setTextureRect(data->param[0]->buttons[i]->sprite,
        data->param[0]->buttons[i]->rect[0]);
    }
}

void check_params_buttons(data_t *data)
{
    for (int i = 0; i < data->param[0]->nb_buttons; i++) {
        check_is_hover(data, i);
    }
}

void set_mouse_rect(data_t *data)
{
    int test = 0;

    for (int i = 0; i < data->menu->nb_buttons; i++)
        if (is_hover(data->menu->buttons[i], data) == sfTrue)
            test = 1;
    if (test == 0)
        sfSprite_setTextureRect(data->window->mouse->sprite,
        (sfIntRect){0, 0, 325.5, 326});
    else
        sfSprite_setTextureRect(data->window->mouse->sprite,
        (sfIntRect){325.5, 0, 325.5, 326});
}

void change_cursor(data_t *data)
{
    sfRenderWindow_setMouseCursorVisible(data->window->window, sfFalse);
    data->window->mouse->posi =
    sfMouse_getPositionRenderWindow(data->window->window);
    data->window->mouse->pos.x = data->window->mouse->posi.x - 5;
    data->window->mouse->pos.y = data->window->mouse->posi.y - 2;
    sfSprite_setPosition(data->window->mouse->sprite,
    data->window->mouse->pos);
}

static void draw_menu_and_buttons(data_t *data)
{
    if (data->prev_scene == MENU)
        draw_sprite_menu(data);
    if (data->prev_scene == PAUSE) {
        sfRenderWindow_setView(data->window->window,
        data->window->gameview);
        draw_sprite_game(data);
        sfRenderWindow_setView(data->window->window, data->window->view);
    }
    sfRenderWindow_drawSprite(data->window->window,
    data->param[0]->bg_sprite, NULL);
    for (int i = 0; i < data->param[0]->nb_buttons; i++) {
        sfRenderWindow_drawSprite(data->window->window,
        data->param[0]->buttons[i]->sprite, NULL);
    }
}

void settings(data_t *data)
{
    change_cursor(data);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->window->clock)) >
    1000 / 60) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        check_params_buttons(data);
        draw_menu_and_buttons(data);
        sfRenderWindow_drawSprite(data->window->window,
        data->window->mouse->sprite, NULL);
        sfRenderWindow_display(data->window->window);
        sfClock_restart(data->window->clock);
    }
}
