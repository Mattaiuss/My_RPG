/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** menu_but_foncs
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void choose_save(data_t *data)
{
    (void)data;
    return;
}

void start_game(data_t *data)
{
    choose_save(data);
    data->prev_scene = MENU;
    data->scene = GAME;
}

void quit_game(data_t *data)
{
    data->scene = -1;
}

void params(data_t *data)
{
    data->prev_scene = MENU;
    data->scene = SETTINGS;
}

void return_menu(data_t *data)
{
    int temp = data->scene;

    data->scene = data->prev_scene;
    data->prev_scene = temp;
}
