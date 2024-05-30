/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** boss_zone
*/

#include "../../../includes/my.h"
#include "../../../includes/rpg.h"

void init_zone3(data_t *data)
{
    data->zones[2]->shape = malloc(sizeof(sfRectangleShape *));
    data->zones[2]->shape = sfRectangleShape_create();
    data->zones[2]->pos = (sfVector2f){10945, 3989};
    data->zones[2]->size = (sfVector2f){1000, 300};
    sfRectangleShape_setPosition(data->zones[2]->shape, data->zones[2]->pos);
    sfRectangleShape_setSize(data->zones[2]->shape, data->zones[2]->size);
    sfRectangleShape_setFillColor(data->zones[2]->shape, (sfColor){0, 0, 255,
    50});
    data->zones[2]->bg = sfSprite_create();
    data->zones[2]->bg_text =
    sfTexture_createFromFile("assets/zones/plain.png", NULL);
    sfSprite_setTexture(data->zones[2]->bg, data->zones[2]->bg_text, sfTrue);
    sfSprite_setScale(data->zones[2]->bg, (sfVector2f){0.73, 0.8});
    data->zones[2]->spawn_rate = 10000;
    data->zones[2]->nb_mobs = 1;
    data->zones[2]->nb_mob_types = 1;
    data->zones[2]->mob_types = malloc(sizeof(int) *
    data->zones[2]->nb_mob_types);
    data->zones[2]->mob_types[0] = BOSS;
}
