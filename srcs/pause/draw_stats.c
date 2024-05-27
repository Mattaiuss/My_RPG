/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** draw_stats
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"
#include <string.h>

static void draw_and_free_arms(data_t *data, char *arm1, char *arm2)
{
    draw_text(data, arm1, (sfVector2f){data->pause->pos.x + 335,
    data->pause->pos.y + 300}, -1);
    draw_text(data, arm2, (sfVector2f){data->pause->pos.x + 335,
    data->pause->pos.y + 330}, -1);
    free(arm1);
    free(arm2);
}

static void draw_arms(data_t *data)
{
    char *arm1 = strdup("1st arm: ");
    char *arm2 = strdup("2nd arm: ");

    if (data->player->inventory->equip[0] == NULL)
        strcat(arm1, "None");
    else {
        arm1 = realloc(arm1, strlen(arm1) +
        strlen(data->player->inventory->equip[0]->item->name) + 1);
        strcat(arm1, data->player->inventory->equip[0]->item->name);
    }
    if (data->player->inventory->equip[1] == NULL)
        strcat(arm2, "None");
    else {
        arm2 = realloc(arm2, strlen(arm2) +
        strlen(data->player->inventory->equip[1]->item->name) + 1);
        strcat(arm2, data->player->inventory->equip[1]->item->name);
    }
    sfText_setCharacterSize(data->pause->text, 20);
    draw_and_free_arms(data, arm1, arm2);
}

static char *draw_atk_stat(int addition_stat, data_t *data)
{
    char *result = NULL;

    if (addition_stat != 0) {
        result = malloc(strlen("+(") + strlen(int_to_str(data->player->atk -
        addition_stat < 1 ? data->player->atk - 1 : addition_stat, 0) +
        strlen(")")) + 1);
        sprintf(result, "%s%s)", addition_stat < 0 ? "-(" : "+(",
        int_to_str(data->player->atk + addition_stat < 1 ? data->player->atk -
        1 : addition_stat, 0));
    }
    return result;
}

static char *draw_def_stat(int addition_stat, data_t *data)
{
    char *result = NULL;

    if (addition_stat != 0) {
        result = malloc(strlen("+(") + strlen(int_to_str(data->player->def +
        addition_stat < 1 ? data->player->def - 1 : addition_stat, 0) +
        strlen(")")) + 1);
        sprintf(result, "%s%s)", addition_stat < 0 ? "-(" : "+(",
        int_to_str(data->player->def + addition_stat < 1 ? data->player->def -
        1 : addition_stat, 0));
    }
    return result;
}

static char *draw_addition_stat(int addition_stat, int stat, data_t *data)
{
    switch (stat) {
        case 0:
            return NULL;
        case 1:
            return draw_atk_stat(addition_stat, data);
        case 2:
            return draw_def_stat(addition_stat, data);
        default:
            return NULL;
    }
}

char *check_arm(data_t *data, int stat)
{
    int addition_stat = 0;

    if (data->player->inventory->equip[0] != NULL) {
        if (data->player->inventory->equip[0]->item->hp != 0 && stat == 0)
            addition_stat += data->player->inventory->equip[0]->item->hp;
        if (data->player->inventory->equip[0]->item->atk != 0 && stat == 1)
            addition_stat += data->player->inventory->equip[0]->item->atk;
        if (data->player->inventory->equip[0]->item->def != 0 && stat == 2)
            addition_stat += data->player->inventory->equip[0]->item->def;
    }
    if (data->player->inventory->equip[1] != NULL) {
        if (data->player->inventory->equip[1]->item->hp != 0 && stat == 0)
            addition_stat += data->player->inventory->equip[1]->item->hp;
        if (data->player->inventory->equip[1]->item->atk != 0 && stat == 1)
            addition_stat += data->player->inventory->equip[1]->item->atk;
        if (data->player->inventory->equip[1]->item->def != 0 && stat == 2)
            addition_stat += data->player->inventory->equip[1]->item->def;
    }
    return draw_addition_stat(addition_stat, stat, data);
}

static void free_name_and_stat(char *name, char *lv, char *hp, char *arms_hp)
{
    free(name);
    free(lv);
    free(hp);
    if (arms_hp != NULL)
        free(arms_hp);
}

static void draw_name_and_stat(data_t *data)
{
    char *name = strdup("\"");
    char *lv = strdup("LV  ");
    char *hp = strdup("HP  ");
    char *arms_hp = check_arm(data, 0);
    char *karma = strdup(data->player->karma < 0 ? "Karma:  -" : "Karma:  ");

    name = strcat(name, data->player->name);
    name = strcat(name, "\"");
    lv = strcat(lv, int_to_str(data->player->lv, 0));
    hp = strcat(hp, int_to_str(data->player->hp, 0));
    hp = strcat(hp, ":");
    hp = strcat(hp, int_to_str(data->player->max_hp, 0));
    karma = strcat(karma, int_to_str(data->player->karma, 0));
    sfText_setCharacterSize(data->pause->text, 20);
    draw_text(data, name, (sfVector2f){PX + 335, PY + 30}, -1);
    draw_text(data, lv, (sfVector2f){PX + 335, PY + 85}, -1);
    draw_text(data, hp, (sfVector2f){PX + 335, PY + 110}, -1);
    draw_text(data, karma, (sfVector2f){PX + 335, PY + 245}, -1);
    free_name_and_stat(name, lv, hp, arms_hp);
}

void display_pause_stats(data_t *data)
{
    char *xp = strdup("XP  ");
    char *atk = strdup("AT  ");
    char *def = strdup("DF  ");
    char *arms_atk = check_arm(data, 1);
    char *arms_def = check_arm(data, 2);

    draw_name_and_stat(data);
    atk = strcat(atk, int_to_str(data->player->atk, 0));
    atk = arms_atk != NULL ? strcat(atk, arms_atk) : atk;
    def = strcat(def, int_to_str(data->player->def, 0));
    def = arms_def != NULL ? strcat(def, arms_def) : def;
    draw_text(data, atk, (sfVector2f){data->pause->pos.x + 335,
    data->pause->pos.y + 165}, -1);
    draw_text(data, def, (sfVector2f){data->pause->pos.x + 335,
    data->pause->pos.y + 190}, -1);
    xp = strcat(xp, int_to_str(data->player->xp, 0));
    draw_text(data, xp, (sfVector2f){data->pause->pos.x + 500,
    data->pause->pos.y + 165}, -1);
    draw_arms(data);
}
