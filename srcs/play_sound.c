/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** play_sound
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void play_sound(data_t *data, char *path)
{
    sfSound_setVolume(data->sound, data->vol);
    data->buffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(data->sound, data->buffer);
    sfSound_play(data->sound);
}
