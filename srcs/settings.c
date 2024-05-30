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

static void disp_volume(data_t *data)
{
    sfRenderWindow_drawSprite(data->window->window,
    data->volume[0]->sprite, NULL);
    sfRenderWindow_drawSprite(data->window->window,
    data->volume[1]->sprite, NULL);
    if (is_hover(data->volume[0], data) == sfTrue &&
    data->keys->left_click == sfTrue) {
        data->volume[0]->callback(data);
        data->keys->left_click = sfFalse;
    }
    if (is_hover(data->volume[1], data) == sfTrue &&
    data->keys->left_click == sfTrue) {
        data->volume[1]->callback(data);
        data->keys->left_click = sfFalse;
    }
}

static void disp_keymap(data_t *data)
{
    sfText *text = create_text(data, (sfVector2f){WIDTH / 2 + 230,
    HEIGHT / 2 - 90}, sfWhite, 30);

    sfRenderWindow_drawSprite(data->window->window,
    data->binds[0]->sprite, NULL);
    sfRenderWindow_drawSprite(data->window->window,
    data->binds[1]->sprite, NULL);
    if (is_hover(data->binds[0], data) == sfTrue &&
    data->keys->left_click == sfTrue) {
        data->binds[0]->callback(data);
        data->keys->left_click = sfFalse;
    }
    if (is_hover(data->binds[1], data) == sfTrue &&
    data->keys->left_click == sfTrue) {
        data->binds[1]->callback(data);
        data->keys->left_click = sfFalse;
    }
    sfText_setString(text, data->keys->up == sfKeyZ ? "AZERTY" : "QWERTY");
    sfRenderWindow_drawText(data->window->window, text, NULL);
    sfText_destroy(text);
}

static void disp_texts(data_t *data)
{
    sfText *text = sfText_create();

    sfText_setFont(text, data->font);
    sfText_setCharacterSize(text, 50);
    sfText_setString(text, "Volume");
    sfText_setPosition(text, (sfVector2f){WIDTH / 2 - 400, HEIGHT / 2 - 175});
    sfRenderWindow_drawText(data->window->window, text, NULL);
    sfText_setString(text, "Keymap");
    sfText_setPosition(text, (sfVector2f){WIDTH / 2 + 200, HEIGHT / 2 - 175});
    sfRenderWindow_drawText(data->window->window, text, NULL);
    sfText_setString(text, int_to_str(data->vol, 2));
    sfText_setPosition(text, (sfVector2f){WIDTH / 2 - 350, HEIGHT / 2 - 100});
    sfRenderWindow_drawText(data->window->window, text, NULL);
    sfText_destroy(text);
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
        disp_volume(data);
        disp_keymap(data);
        disp_texts(data);
        sfRenderWindow_drawSprite(data->window->window,
        data->window->mouse->sprite, NULL);
        sfRenderWindow_display(data->window->window);
        sfClock_restart(data->window->clock);
    }
}
