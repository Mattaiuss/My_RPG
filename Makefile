##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## rpg
##

NAME	=	my_rpg

SRC	=	srcs/window.c \
		lib/my_super_str_cat.c \
		lib/my_strlen.c \
		lib/int_to_str.c \
		lib/manage_line.c \
		srcs/init/init.c \
		srcs/init/init_items.c \
		srcs/init/init_item_infos.c \
		srcs/init/init_inventory.c \
		srcs/init/init_menu.c \
		srcs/init/init_keys.c \
		srcs/init/init_param.c \
		srcs/init/init_characters.c \
		srcs/init/init_zones.c \
		srcs/menu_but_foncs.c \
		srcs/menu.c \
		srcs/game.c \
		srcs/dialogue.c \
		srcs/disp_saves.c \
		srcs/settings.c \
		srcs/events.c \
		srcs/button.c \
		srcs/pause/pause.c \
		srcs/pause/pause_texts.c \
		srcs/pause/pause_index.c \
		srcs/events_keys.c \
		srcs/collisions.c \
		srcs/movements.c \
		srcs/pause/draw_item_infos.c \
		srcs/pause/draw_text.c \
		srcs/pause/draw_stats.c \
		srcs/pause/item_actions.c \
		srcs/pause/pause_equip.c	\
		srcs/reset_view.c \
		srcs/game_over.c \
		srcs/zone.c \
		srcs/spawn_enemy.c \
		srcs/init/zones/field_zone.c \
		srcs/init/zones/forest_zone.c \
		srcs/init/init_npc.c \
		srcs/init/npcs/init_npc03.c \
		srcs/init/npcs/init_npc47.c \
		srcs/init/npcs/init_npc811.c \
		srcs/init/npcs/init_npc1215.c \
		srcs/init/npcs/init_npc1617.c \
		srcs/init/init_monsters.c \
		srcs/init/monsters/init_slime.c \
		srcs/init/monsters/init_treant.c \
		srcs/init/monsters/init_skeleton.c \
		srcs/init/attacks/init_attacks.c \
		srcs/combat/combat_actions.c \
		srcs/combat/combat.c \
		srcs/combat/fight.c \
		srcs/combat/print_effects.c \
		srcs/combat/set_endfight.c \
		srcs/combat/disp_additionnal.c \
		srcs/quest/init_quests.c \
		srcs/quest/init_quest69.c \
		srcs/quest/quest_foncs.c \
		srcs/quest/quest_foncs2.c \
		srcs/quest/quest_foncs3.c \
		srcs/save_game.c \
		srcs/destroy/destroy_all.c \
		srcs/destroy/destroy_scenes.c \
		srcs/init/init_volume.c \
		srcs/play_sound.c \
		srcs/init/monsters/init_boss.c \
		srcs/init/zones/boss_zone.c \
		srcs/display_end.c \

OBJ	=	$(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS	=	-W -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CSFML)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
