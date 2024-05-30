/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** forest_zone
*/

#include "../../../includes/my.h"
#include "../../../includes/rpg.h"

void init_zone1(data_t *data)
{
    data->zones[0]->shape = malloc(sizeof(sfRectangleShape *));
    data->zones[0]->shape = sfRectangleShape_create();
    data->zones[0]->pos = (sfVector2f){1135, 955};
    data->zones[0]->size = (sfVector2f){5569, 2521};
    sfRectangleShape_setPosition(data->zones[0]->shape, data->zones[0]->pos);
    sfRectangleShape_setSize(data->zones[0]->shape, data->zones[0]->size);
    sfRectangleShape_setFillColor(data->zones[0]->shape, (sfColor){255, 0, 0,
    50});
    data->zones[0]->bg = sfSprite_create();
    data->zones[0]->bg_text =
    sfTexture_createFromFile("assets/zones/wood.png", NULL);
    sfSprite_setTexture(data->zones[0]->bg, data->zones[0]->bg_text, sfTrue);
    sfSprite_setScale(data->zones[0]->bg, (sfVector2f){3.2, 3.1});
    data->zones[0]->spawn_rate = 500;
    data->zones[0]->nb_mobs = 50;
    data->zones[0]->nb_mob_types = 2;
    data->zones[0]->mob_types = malloc(sizeof(int) *
    data->zones[0]->nb_mob_types);
    data->zones[0]->mob_types[0] = SLIME;
    data->zones[0]->mob_types[1] = TRE;
}
