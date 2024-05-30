/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** init_zones
*/

#include "../../includes/my.h"
#include "../../includes/rpg.h"

void init_zones(data_t *data)
{
    data->zones = malloc(sizeof(zone_t) * 3);
    data->zones[0] = malloc(sizeof(zone_t));
    data->zones[1] = malloc(sizeof(zone_t));
    data->zones[2] = malloc(sizeof(zone_t));
    init_zone1(data);
    init_zone2(data);
    init_zone3(data);
    data->current_zone = NULL;
}
