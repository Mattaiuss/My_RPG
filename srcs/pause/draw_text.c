/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** draw_text
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void drawitm_text(data_t *data, char *str, sfVector2f pos, int index)
{
    sfText_setString(data->pause->text, str);
    sfText_setPosition(data->pause->text, pos);
    if (data->pause->item_index == index)
        sfText_setColor(data->pause->text, sfYellow);
    else
        sfText_setColor(data->pause->text, sfWhite);
    sfRenderWindow_drawText(data->window->window, data->pause->text, NULL);
}

void drawequip_text(data_t *data, char *str, sfVector2f pos, int index)
{
    sfText_setString(data->pause->text, str);
    sfText_setPosition(data->pause->text, pos);
    if (data->pause->equip_index == index)
        sfText_setColor(data->pause->text, sfYellow);
    else
        sfText_setColor(data->pause->text, sfWhite);
    sfRenderWindow_drawText(data->window->window, data->pause->text, NULL);
}

void drawact_text(data_t *data, char *str, sfVector2f pos, int index)
{
    sfText_setString(data->pause->text, str);
    sfText_setPosition(data->pause->text, pos);
    if (data->pause->action_index == index)
        sfText_setColor(data->pause->text, sfYellow);
    else
        sfText_setColor(data->pause->text, sfWhite);
    sfRenderWindow_drawText(data->window->window, data->pause->text, NULL);
}

void draw_text(data_t *data, char *str, sfVector2f pos, int index)
{
    sfText_setString(data->pause->text, str);
    sfText_setPosition(data->pause->text, pos);
    if (data->pause->index == index)
        sfText_setColor(data->pause->text, sfYellow);
    else
        sfText_setColor(data->pause->text, sfWhite);
    sfRenderWindow_drawText(data->window->window, data->pause->text, NULL);
}
