/*
** EPITECH PROJECT, 2024
** main file
** File description:
** rpg
*/

#include "../includes/rpg.h"
#include "../includes/my.h"

void set_collision_map(data_t *data, char *buffer, int nb_coords, int size)
{
    data->collision_map = malloc(sizeof(int) * (nb_coords * 2 + 1));
    for (int i = 0; i < nb_coords * 2; i++) {
        data->collision_map[i] = 0;
    }
    data->collision_map[nb_coords * 2] = -1;
    for (int i = 0; i < size && data->collision_map[i] != -1; i++) {
        data->collision_map[i] = atoi(buffer);
        while (buffer[0] != ' ' && buffer[0] != '\0' && buffer[0] != '\n')
            buffer++;
        buffer++;
    }
}

void get_collisions(data_t *data)
{
    int fd = open("res.coll", O_RDONLY);
    ssize_t size = 0;
    char *buffer = NULL;
    int nb_coords = 0;

    if (fd == -1)
        return;
    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    buffer = malloc(sizeof(char) * size);
    read(fd, buffer, size);
    for (int i = 0; i < size && buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nb_coords++;
    }
    set_collision_map(data, buffer, nb_coords, size);
}

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));

    init_basics(data);
    data->nb_entities[0] = 1;
    data->nb_entities[1] = 0;
    data->nb_entities[2] = 18;
    init_menu(data);
    init_params(data);
    init_keys(data);
    init_game(data);
    init_fight(data);
    init_soul(data);
    init_player(data);
    init_pause(data);
    init_items(data);
    init_inventory(data);
    get_collisions(data);
    init_quest(data);
    init_npc(data);
    return (data);
}

static void cinematic(data_t *data)
{
    (void)data;
}

static void game_loop(data_t *data)
{
    while (data->scene == CINEMATIC)
        cinematic(data);
    restart_music(data);
    while (data->scene == MENU || data->scene == SAVES)
        menu(data);
    while (data->scene == SETTINGS)
        settings(data);
    restart_music(data);
    while (data->scene == GAME || data->scene == PAUSE ||
    data->scene == COMBAT || data->scene == DIALOGUE || data->scene == SHOP)
        game(data);
    while (data->scene == GAME_OVER)
        display_go(data);
    while (data->scene == END)
        display_end(data);
    if (data->scene == -1)
        return;
}

int my_rpg(void)
{
    data_t *data = init_data();
    sfImage *icon = sfImage_createFromFile("assets/icon.png");

    sfRenderWindow_setIcon(data->window->window, 1600,
    1600, sfImage_getPixelsPtr(icon));
    srand(time(NULL));
    while (data->scene != -1 && sfRenderWindow_isOpen(data->window->window)) {
        game_loop(data);
    }
    sfMusic_stop(data->music);
    destroy_all(data);
    return (0);
}

int main(int ac, __attribute__((unused))char **av)
{
    return (ac == 1 ? my_rpg() : 84);
}
