/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** display_end
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void disp_end_screen(data_t *data)
{
    static sfSprite *end = NULL;
    static sfTexture *end_texture = NULL;

    if (end == NULL) {
        sfMusic_stop(data->music);
        end = sfSprite_create();
        end_texture = sfTexture_createFromFile("assets/end.jpg", NULL);
        sfSprite_setTexture(end, end_texture, sfTrue);
        sfSprite_setPosition(end, (sfVector2f){data->player->pos.x - 515,
            data->player->pos.y - 250});
        sfSprite_setScale(end, (sfVector2f){0.5, 0.5});
    }
    sfRenderWindow_drawSprite(data->window->window, end, NULL);
}

void display_end(data_t *data)
{
    sfRenderWindow_clear(data->window->window, sfBlack);
    manage_events(data);
    disp_end_screen(data);
    sfRenderWindow_display(data->window->window);
}
