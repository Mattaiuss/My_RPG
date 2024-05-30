/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** game
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

static void set_print_top_dialogue(data_t *data, int id_npc_dial)
{
    sfText *text = create_text(data, (sfVector2f){data->player->pos.x - 440,
    data->player->pos.y + 115}, sfWhite, 20);

    sfSprite_setPosition(D_PAUSE->action_sprite, (sfVector2f)
    {data->player->pos.x - 450, data->player->pos.y + 20});
    sfSprite_setScale(data->pause->action_sprite, (sfVector2f){0.103, 0.095});
    sfRenderWindow_drawSprite(WIN, D_PAUSE->action_sprite, NULL);
    sfSprite_setPosition(D_PAUSE->action_sprite, (sfVector2f)
    {data->player->pos.x - 470, data->player->pos.y + 110});
    sfSprite_setScale(data->pause->action_sprite, (sfVector2f){0.153, 0.035});
    sfRenderWindow_drawSprite(WIN, D_PAUSE->action_sprite, NULL);
    sfText_setString(text, data->npcs[id_npc_dial]->name);
    sfRenderWindow_drawText(WIN, text, NULL);
}

static void set_font_dialogue(data_t *data, int id_npc_dial)
{
    int row = id_npc_dial / 6;
    int col = id_npc_dial % 6;

    set_print_top_dialogue(data, id_npc_dial);
    sfSprite_setPosition(D_PAUSE->action_sprite, (sfVector2f)
    {data->player->pos.x - 500, data->player->pos.y + 150});
    sfSprite_setScale(data->pause->action_sprite, (sfVector2f){0.8, 0.1});
    sfRenderWindow_drawSprite(WIN, D_PAUSE->action_sprite, NULL);
    sfSprite_setPosition(data->dialogue_sprite, (sfVector2f)
    {data->player->pos.x - 445, data->player->pos.y + 23});
    sfSprite_setTextureRect(data->dialogue_sprite, (sfIntRect)
    {col * 32, row * 32, 32, 32});
    sfSprite_setScale(data->dialogue_sprite, (sfVector2f){2.5, 2.5});
    sfRenderWindow_drawSprite(WIN, data->dialogue_sprite, NULL);
}

static void init_partial_text(char *formattedText, int i, sfText *sfText)
{
    char partialText[i + 2];

    strncpy(partialText, formattedText, i + 1);
    partialText[i + 1] = '\0';
    sfText_setString(sfText, partialText);
}

sfText *create_text(data_t *data, sfVector2f position, sfColor color, int siz)
{
    sfText *sfText = sfText_create();

    sfText_setFont(sfText, data->font);
    sfText_setCharacterSize(sfText, siz);
    sfText_setColor(sfText, color);
    sfText_setPosition(sfText, position);
    return sfText;
}

void drraw_text(char *text, sfVector2f position, data_t *data, int id_npc_dial)
{
    sfText *sfText = create_text(data, position, sfWhite, 20);
    char *nwtext = NULL;

    nwtext = add_newline_if_needed(sfText, D_PAUSE->action_sprite, text, 100);
    for (int i = 0; i < my_strlen(nwtext); i++) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        if (data->scene != DIALOGUE)
            break;
        draw_sprite_game(data);
        set_font_dialogue(data, id_npc_dial);
        init_partial_text(nwtext, i, sfText);
        sfRenderWindow_drawText(data->window->window, sfText, NULL);
        sfRenderWindow_display(data->window->window);
        sfSleep(sfMilliseconds(40));
    }
    sfText_destroy(sfText);
}

sfBool is_npc_quest(data_t *data, npc_t *npc)
{
    if (npc->quest_npc == sfTrue) {
        if (npc->id == 10 && data->quest->title[6] == '6')
            return sfTrue;
        if (npc->id == 17 && data->quest->title[6] == '9')
            return sfTrue;
    }
    return sfFalse;
}

static void check_finish(data_t *data, int result, npc_t *npc)
{
    if (result == -1 && data->scene == DIALOGUE && npc->type == SIMP) {
        data->prev_scene = DIALOGUE;
        data->scene = GAME;
    }
    if (result == -1 && data->scene == DIALOGUE && npc->type == MARCHAND) {
        data->prev_scene = DIALOGUE;
        data->scene = SHOP;
    }
}

void disp_dialogue(data_t *data, npc_t *npc)
{
    sfVector2f playerPos = {DIALOGUE_POS};
    FILE *file = fopen(CHECK_QUEST, "r");
    char *line = NULL;
    size_t len = 0;
    int result;

    if (file != NULL) {
        result = getline(&line, &len, file);
        while (result != -1 && data->scene == DIALOGUE) {
            drraw_text(line, playerPos, data, npc->id);
            manage_events(data);
            sfRenderWindow_display(data->window->window);
            sfSleep(sfSeconds(1));
            result = getline(&line, &len, file);
        }
        free(line);
        fclose(file);
        check_finish(data, result, npc);
    }
}

void dialogue(data_t *data, npc_t *npc)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->window->clock))
    > 1000 / 60) {
        sfRenderWindow_clear(data->window->window, sfBlack);
        manage_events(data);
        disp_dialogue(data, npc);
        sfRenderWindow_display(data->window->window);
        sfClock_restart(data->window->clock);
        sfSprite_setScale(data->pause->action_sprite, (sfVector2f){0.2, 0.2});
    }
}
