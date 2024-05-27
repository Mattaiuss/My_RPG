/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init
*/

#include "../../includes/my.h"
#include "../../includes/rpg.h"

void init_game(data_t *data)
{
    data->game = malloc(sizeof(game_t));
    data->game->map_bas_sprite = malloc(sizeof(sfSprite *));
    data->game->map_bas_sprite = sfSprite_create();
    data->game->map_bas_text = sfTexture_createFromFile(MAP_BAS, NULL);
    sfSprite_setTexture(data->game->map_bas_sprite,
    data->game->map_bas_text, sfTrue);
    sfSprite_setScale(data->game->map_bas_sprite, (sfVector2f){2, 2});
    data->game->map_haut_sprite = malloc(sizeof(sfSprite *));
    data->game->map_haut_sprite = sfSprite_create();
    data->game->map_haut_text = sfTexture_createFromFile(MAP_HAUT, NULL);
    sfSprite_setTexture(data->game->map_haut_sprite,
    data->game->map_haut_text, sfTrue);
    sfSprite_setScale(data->game->map_haut_sprite, (sfVector2f){2, 2});
}

static void init_fight_but(data_t *data)
{
    sfIntRect rect = {0, 0, 110, 42};

    data->combat->buttons = malloc(sizeof(button_t *) * 4);
    for (int i = 0; i < 4; i ++) {
        data->combat->buttons[i] = malloc(sizeof(button_t));
        data->combat->buttons[i]->sprite = sfSprite_create();
    }
    data->combat->buttons[0]->texture = TEXT("assets/fight/fight.png", NULL);
    data->combat->buttons[1]->texture = TEXT("assets/fight/act.png", NULL);
    data->combat->buttons[2]->texture = TEXT("assets/fight/item.png", NULL);
    data->combat->buttons[3]->texture = TEXT("assets/fight/mercy.png", NULL);
    for (int i = 0; i < 4; i ++) {
        sfSprite_setTexture(data->combat->buttons[i]->sprite,
        data->combat->buttons[i]->texture, sfTrue);
        sfSprite_setTextureRect(data->combat->buttons[i]->sprite, rect);
        sfSprite_setScale(data->combat->buttons[i]->sprite,
        (sfVector2f){1.75, 1.75});
    }
}

void init_fight(data_t *data)
{
    data->combat = malloc(sizeof(combat_t));
    data->combat->status = 0;
    data->combat->index_button = 0;
    data->combat->animation = sfClock_create();
    data->combat->invul = sfClock_create();
    data->combat->f_square = sfSprite_create();
    data->combat->act_clock = sfClock_create();
    data->combat->f_texture =
    sfTexture_createFromFile("assets/fight/f_square.png", NULL);
    sfSprite_setTexture(data->combat->f_square,
    data->combat->f_texture, sfTrue);
    sfSprite_setScale(data->combat->f_square, (sfVector2f){2, 2});
    data->combat->a_square = sfSprite_create();
    data->combat->a_texture =
    sfTexture_createFromFile("assets/fight/a_square.png", NULL);
    sfSprite_setTexture(data->combat->a_square,
    data->combat->a_texture, sfTrue);
    sfSprite_setScale(data->combat->a_square, (sfVector2f){0.75, 0.7});
    init_fight_but(data);
}

void init_pause(data_t *data)
{
    data->pause = malloc(sizeof(pause_t));
    data->pause->status = 0;
    data->pause->index = 0;
    data->pause->action_index = 0;
    data->pause->equip_index = 0;
    data->pause->item_index = 0;
    data->pause->action_sprite = sfSprite_create();
    data->pause->action_text =
    sfTexture_createFromFile("assets/pause/pause2.png", NULL);
    sfSprite_setTexture(data->pause->action_sprite, data->pause->action_text,
    sfTrue);
    sfSprite_setScale(data->pause->action_sprite, (sfVector2f){0.2, 0.2});
    data->pause->pause_menu_sprite = sfSprite_create();
    data->pause->pause_menu_text =
    sfTexture_createFromFile("assets/pause/pause.png", NULL);
    sfSprite_setTexture(data->pause->pause_menu_sprite,
    data->pause->pause_menu_text, sfTrue);
    sfSprite_setScale(data->pause->pause_menu_sprite, (sfVector2f){0.5, 0.5});
}

void init_window(data_t *data)
{
    data->window = malloc(sizeof(window_t));
    data->window->mode = (sfVideoMode){WIDTH, HEIGHT, 32};
    data->window->window = sfRenderWindow_create(data->window->mode,
    "My RPG", sfClose | sfResize, NULL);
    data->window->clock = sfClock_create();
    data->scene = MENU;
    data->prev_scene = -2;
    data->window->mouse = malloc(sizeof(mouse_t));
    data->window->mouse->sprite = sfSprite_create();
    data->window->mouse->texture = sfTexture_createFromFile(CURSOR, NULL);
    sfSprite_setTexture(data->window->mouse->sprite,
    data->window->mouse->texture, sfTrue);
    sfSprite_setTextureRect(data->window->mouse->sprite,
    (sfIntRect){0, 0, 325.5, 326});
    sfSprite_setScale(data->window->mouse->sprite, (sfVector2f){0.1, 0.1});
    data->window->mouse->pos = (sfVector2f){0, 0};
    sfSprite_setPosition(data->window->mouse->sprite,
    data->window->mouse->pos);
    data->window->mouse_pos = (sfVector2f){0, 0};
}

void init_basics(data_t *data)
{
    init_window(data);
    data->music = sfMusic_createFromFile("assets/musics/menu.ogg");
    sfMusic_play(data->music);
    sfMusic_setLoop(data->music, sfTrue);
    data->combat_music = sfMusic_createFromFile("assets/musics/battle.ogg");
    sfMusic_setLoop(data->combat_music, sfTrue);
    data->window->gameview =
    sfView_createFromRect((sfFloatRect){0, 0, WIDTH, HEIGHT});
    data->window->view =
    sfView_createFromRect((sfFloatRect){0, 0, WIDTH, HEIGHT});
    data->window->view_pos = (sfVector2f){0, 0};
    data->font = sfFont_createFromFile("assets/font.ttf");
    data->player = malloc(sizeof(player_t));
    init_zones(data);
    init_monsters(data);
}
