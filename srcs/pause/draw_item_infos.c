/*
** EPITECH PROJECT, 2024
** under_rpg
** File description:
** draw_item_infos
*/

#include "../../includes/my.h"
#include "../../includes/rpg.h"

int val_id_item_compens(int id)
{
    if (id == 8 || id == 9)
        return 10;
    return 0;
}

item_texts_t allocate_item_texts(data_t *data, box_t *tmp)
{
    item_texts_t texts;

    (void)data;
    texts.name = allocate_text("Name: ", tmp->item->name);
    texts.desc = allocate_text("Description: \n", tmp->item->description);
    texts.type = allocate_text("Type: ", tmp->item->type == CONSUMABLE ?
    "Consumable" : "Equipment");
    texts.atk = allocate_text("Atk: ", int_to_str(tmp->item->atk, 1));
    texts.def = allocate_text("Def: ", int_to_str(tmp->item->def, 1));
    texts.hp = allocate_text("Hp: ", int_to_str(tmp->item->hp, 1));
    texts.gold = allocate_text("Gold: ", int_to_str(tmp->item->gold, 1));
    return texts;
}

void set_sprites(data_t *data, box_t *tmp)
{
    sfSprite_setPosition(D_PAUSE->action_sprite, (sfVector2f){PX + 250, PY});
    sfSprite_setScale(data->pause->action_sprite, (sfVector2f){0.6, 0.5});
    sfRenderWindow_drawSprite(WIN, D_PAUSE->action_sprite, NULL);
    sfSprite_setPosition(tmp->item->sprite, (sfVector2f){PX + 280 +
    val_id_item_compens(tmp->item->id), PY + 33});
    sfRenderWindow_drawSprite(WIN, tmp->item->sprite, NULL);
}

void draw_texts(data_t *data, item_texts_t txt, box_t *tmp)
{
    int ms = 0;

    sfText_setCharacterSize(data->pause->text, 18);
    txt.name = add_newline_if_needed(D_PAUSE->text, D_PAUSE->action_sprite,
    txt.name, 170);
    drawact_text(data, txt.name, (sfVector2f){PX + 430, PY + 53}, 2);
    txt.desc = add_newline_if_needed(D_PAUSE->text, D_PAUSE->action_sprite,
    txt.desc, 170);
    drawact_text(data, txt.desc, (sfVector2f){PX + 400, PY + 123}, 0);
    ms = count_newlines(txt.desc) * 18;
    drawact_text(data, txt.type, (sfVector2f){PX + 400, PY + 183 + ms}, 0);
    if (tmp->item->type != CONSUMABLE) {
        drawact_text(data, txt.atk, (sfVector2f){PX + 400, PY + 223 + ms}, 0);
        drawact_text(data, txt.def, (sfVector2f){PX + 400, PY + 253 + ms}, 0);
        drawact_text(data, txt.gold, (sfVector2f){PX + 400, PY + 283 + ms}, 0);
    }
}
