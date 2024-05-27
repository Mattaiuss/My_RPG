/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** menu
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void draw_menu_buttons(data_t *data)
{
    for (int i = 0; i < data->menu->nb_buttons; i++) {
        sfRenderWindow_drawSprite(data->window->window,
        data->menu->buttons[i]->sprite, NULL);
    }
}

void draw_sprite_menu(data_t *data)
{
    sfRenderWindow_drawSprite(data->window->window,
    data->menu->bg_sprite, NULL);
    draw_menu_buttons(data);
}

void check_is_clicked(data_t *data, int i)
{
    if (data->keys->left_click == sfTrue) {
        data->menu->buttons[i]->callback(data);
        data->keys->left_click = sfFalse;
    }
}

void check_menu_buttons(data_t *data)
{
    for (int i = 0; i < data->menu->nb_buttons; i++) {
        if (is_hover(data->menu->buttons[i], data) == sfTrue) {
            sfSprite_setTextureRect(data->menu->buttons[i]->sprite,
            data->menu->buttons[i]->rect[1]);
            check_is_clicked(data, i);
        } else {
            sfSprite_setTextureRect(data->menu->buttons[i]->sprite,
            data->menu->buttons[i]->rect[0]);
        }
    }
    set_mouse_rect(data);
}

void menu(data_t *data)
{
    change_cursor(data);
    if (data->scene == SAVES)
        return draw_saves(data);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->window->clock))
    > 1000 / 60) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        check_menu_buttons(data);
        draw_sprite_menu(data);
        sfRenderWindow_drawSprite(data->window->window,
        data->window->mouse->sprite, NULL);
        sfRenderWindow_display(data->window->window);
        sfClock_restart(data->window->clock);
    }
}
