/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** combat_actions
*/

#include "../../includes/rpg.h"
#include "../../includes/my.h"

void check_start_fight(data_t *data)
{
    data->combat->current_wave = data->current_enemy->waves[rand() %
    data->current_enemy->nb_waves];
    if (data->combat->status == 0) {
        data->combat->status = 1;
        if (data->combat->byakuya_used == 1) {
            data->player->atk_cb = data->player->atk;
            data->combat->byakuya_used = 2;
        }
    }
    update_atk_cb(data);
    data->current_enemy->life -= EN_DAMAGES;
    if (data->current_enemy->life <= 0) {
        sfMusic_stop(data->combat_music);
        sfMusic_play(data->music);
        return set_gameover(data);
    }
}

void print_animation_weapons(int id, int ty, sfSound *sound, sfSoundBuffer *bf)
{
    sfSound_setBuffer(sound, bf);
    sfSound_play(sound);
    if (id == 8 || id == 9) {
        if (id == 9)
            print_rukia_effect();
        if (id == 8)
            print_byakuya_effect();
        return;
    }
    if (ty == SWORD)
        return print_sword_effect();
    if (ty == MAGIC)
        return print_magic_effect();
    if (ty == NONE)
        return print_punch_effect();
}

static void punch(data_t *data, sfSoundBuffer *buffer, sfSound *sound)
{
    (void)data;
    buffer = sfSoundBuffer_createFromFile("assets/items/punch.ogg");
    sound = sfSound_create();
    print_animation_weapons(0, NONE, sound, buffer);
    sfSleep(sfMilliseconds(1000));
    sfSound_destroy(sound);
    sfSoundBuffer_destroy(buffer);
}

static int check_norm_arm(box_t *equip, int weapon)
{
    if (equip == NULL)
        return 0;
    if (equip->item->weapon == weapon)
        return 1;
    return 0;
}

void if_3(data_t *data, sfSoundBuffer *buffer, sfSound *sound)
{
    if (check_norm_arm(data->player->inventory->equip[0], SWORD) == 1 ||
    check_norm_arm(data->player->inventory->equip[1], SWORD) == 1) {
        buffer = sfSoundBuffer_createFromFile("assets/items/sword.ogg");
        sound = sfSound_create();
        print_animation_weapons(0, SWORD, sound, buffer);
        sfSleep(sfMilliseconds(200));
        sfSound_destroy(sound);
        sfSoundBuffer_destroy(buffer);
    } else if (check_norm_arm(data->player->inventory->equip[0], MAGIC) == 1 ||
    check_norm_arm(data->player->inventory->equip[1], MAGIC) == 1) {
        buffer = sfSoundBuffer_createFromFile("assets/items/magic.ogg");
        sound = sfSound_create();
        print_animation_weapons(0, MAGIC, sound, buffer);
        sfSleep(sfMilliseconds(2500));
        sfSound_destroy(sound);
        sfSoundBuffer_destroy(buffer);
    } else
        punch(data, buffer, sound);
}

static void if_2(data_t *data, sfSoundBuffer *buffer, sfSound *sound)
{
    int random_weapon = 0;

    if ((check_norm_arm(data->player->inventory->equip[0], SWORD) == 1 &&
    check_norm_arm(data->player->inventory->equip[1], MAGIC) == 1) ||
    (check_norm_arm(data->player->inventory->equip[0], MAGIC) == 1 &&
    check_norm_arm(data->player->inventory->equip[1], SWORD) == 1)) {
        random_weapon = rand() % 2;
        sound = sfSound_create();
        if (random_weapon == 0) {
            buffer = sfSoundBuffer_createFromFile("assets/items/sword.ogg");
            print_animation_weapons(0, SWORD, sound, buffer);
        } else {
            buffer = sfSoundBuffer_createFromFile("assets/items/magic.ogg");
            print_animation_weapons(0, MAGIC, sound, buffer);
        }
        sfSleep(sfMilliseconds(random_weapon == 0 ? 200 : 2500));
        sfSound_destroy(sound);
        sfSoundBuffer_destroy(buffer);
    } else
        if_3(data, buffer, sound);
}

static int check_spe_arm(data_t *data, int id)
{
    if (data->player->inventory->equip[0] == NULL &&
    data->player->inventory->equip[1] == NULL)
        return 0;
    if (data->player->inventory->equip[0] != NULL) {
        if (data->player->inventory->equip[0]->item->id == id)
            return 1;
    }
    if (data->player->inventory->equip[1] != NULL) {
        if (data->player->inventory->equip[1]->item->id == id)
            return 1;
    }
    return 0;
}

int check_rukia(data_t *data)
{
    sfSoundBuffer *buffer = NULL;
    sfSound *sound = NULL;

    if (check_spe_arm(data, 9) == 1 && data->combat->rukia
    == sfTrue && data->combat->rukia_used == 0) {
        buffer = sfSoundBuffer_createFromFile("assets/items/rukia.ogg");
        sound = sfSound_create();
        print_animation_weapons(9, SWORD, sound, buffer);
        sfSleep(sfSeconds(3));
        data->combat->rukia_used = 1;
        data->combat->status = 0;
        sfSound_destroy(sound);
        sfSoundBuffer_destroy(buffer);
        return 1;
    }
    return 0;
}

static void check_arms(data_t *data)
{
    sfSoundBuffer *buffer = NULL;
    sfSound *sound = NULL;

    if (check_spe_arm(data, 8) == 1 && data->combat->byakuya
    == sfTrue && data->combat->byakuya_used == 0) {
        buffer = sfSoundBuffer_createFromFile("assets/items/byakuya.ogg");
        sound = sfSound_create();
        print_animation_weapons(8, SWORD, sound, buffer);
        sfSleep(sfSeconds(4));
        data->player->atk_cb *= 1.5;
        data->combat->byakuya_used = 1;
    } else
        if_2(data, buffer, sound);
    sfSound_destroy(sound);
    sfSoundBuffer_destroy(buffer);
}

void fight(data_t *data)
{
    check_start_fight(data);
    if (check_rukia(data) != 1)
        check_arms(data);
    for (int i = 0; i < data->combat->current_wave->nb_attacks; i ++) {
        data->combat->current_wave->attacks[i]->pos =
        data->combat->current_wave->attacks[i]->og_pos;
        data->combat->current_wave->attacks[i]->pos =
        (sfVector2f){data->player->pos.x +
        data->combat->current_wave->attacks[i]->pos.x,
        data->player->pos.y +
        data->combat->current_wave->attacks[i]->pos.y};
        sfSprite_setPosition(
            data->combat->current_wave->attacks[i]->sprite,
            data->combat->current_wave->attacks[i]->pos);
    }
    sfClock_restart(data->combat->animation);
    sfClock_restart(data->combat->current_wave->clock);
}
