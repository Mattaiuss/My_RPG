/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** save_game
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

static void error_msg(data_t *data)
{
    write(1, "Error: Can't open save file\n", 28);
    data->pause->status = 0;
}

void save_game(data_t *data)
{
    FILE *file = fopen("saves/save.dat", "w");
    int index_quest = 0;

    if (file == NULL)
        return error_msg(data);
    fwrite(&data->player->pos, sizeof(sfVector2f), 1, file);
    fwrite(&data->player->atk, sizeof(int), 1, file);
    fwrite(&data->player->def, sizeof(int), 1, file);
    fwrite(&data->player->hp, sizeof(int), 1, file);
    fwrite(&data->player->lv, sizeof(int), 1, file);
    fwrite(&data->player->max_hp, sizeof(int), 1, file);
    fwrite(&data->player->xp, sizeof(int), 1, file);
    fwrite(&data->player->gold, sizeof(int), 1, file);
    fwrite(&data->player->karma, sizeof(int), 1, file);
    index_quest = data->quest->title[6] - 48;
    fwrite(&index_quest, sizeof(int), 1, file);
    fwrite(&data->mob_killed, sizeof(int), 1, file);
    fclose(file);
    write(1, "Game saved\n", 11);
    data->pause->status = 0;
}
