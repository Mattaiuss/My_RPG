/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** pause_equip
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"
#include <string.h>

char *set_equip_text(data_t *data)
{
    char *equip = NULL;

    if (D_PAUSE->item_index < 10) {
        equip = strdup(PL->inventory->invento[D_PAUSE->item_index]->item->type
        == CONSUMABLE ? "Use" : "Equip");
    } else {
        equip = strdup("Unequip");
    }
    return equip;
}

void display_item_menu(data_t *data)
{
    char *equip = set_equip_text(data);
    char *drop = strdup("Drop");
    char *infos = strdup("Infos");

    sfSprite_setPosition(data->pause->action_sprite, (sfVector2f){
        data->pause->pos.x + 700, data->pause->pos.y + 10});
    sfRenderWindow_drawSprite(data->window->window,
    data->pause->action_sprite, NULL);
    sfText_setCharacterSize(data->pause->text, 20);
    drawact_text(data, equip, (sfVector2f){data->pause->pos.x + 724,
    data->pause->pos.y + 24}, 0);
    drawact_text(data, drop, (sfVector2f){data->pause->pos.x + 724,
    data->pause->pos.y + 56}, 1);
    drawact_text(data, infos, (sfVector2f){data->pause->pos.x + 724,
    data->pause->pos.y + 88}, 2);
    free(equip);
    free(drop);
    free(infos);
}

void disp_equip_menu(data_t *data)
{
    char *arm1 = strdup(data->player->inventory->equip[0] == NULL ?
    "Empty" : "Arm1");
    char *arm2 = strdup(data->player->inventory->equip[1] == NULL ?
    "Empty" : "Arm2");

    sfText_setCharacterSize(data->pause->text, 18);
    drawequip_text(data, arm1, (sfVector2f){data->pause->pos.x + 724,
    data->pause->pos.y + 130}, 0);
    drawequip_text(data, arm2, (sfVector2f){data->pause->pos.x + 724,
    data->pause->pos.y + 150}, 1);
    free(arm1);
    free(arm2);
}
