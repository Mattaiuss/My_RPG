/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** field_zone
*/

#include "../../../includes/my.h"
#include "../../../includes/rpg.h"

void init_zone2(data_t *data)
{
    data->zones[1]->shape = malloc(sizeof(sfRectangleShape *));
    data->zones[1]->shape = sfRectangleShape_create();
    data->zones[1]->pos = (sfVector2f){4589, 3923};
    data->zones[1]->size = (sfVector2f){3159, 1002};
    sfRectangleShape_setPosition(data->zones[1]->shape, data->zones[1]->pos);
    sfRectangleShape_setSize(data->zones[1]->shape, data->zones[1]->size);
    sfRectangleShape_setFillColor(data->zones[1]->shape, (sfColor){0, 255, 0,
    50});
    data->zones[1]->bg = sfSprite_create();
    data->zones[1]->bg_text =
    sfTexture_createFromFile("assets/zones/field.jpg", NULL);
    sfSprite_setTexture(data->zones[1]->bg, data->zones[1]->bg_text, sfTrue);
    sfSprite_setScale(data->zones[1]->bg, (sfVector2f){0.73, 0.8});
    data->zones[1]->spawn_rate = 600;
    data->zones[1]->nb_mobs = 0;
    data->zones[1]->nb_mob_types = 0;
    data->zones[1]->mob_types = NULL;
}
