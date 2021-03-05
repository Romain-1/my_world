##
## EPITECH PROJECT, 2020
## my_world
## File description:
## Makefile
##

LDFLAGS	=	-l csfml-graphics	\
		-l csfml-window		\
		-l csfml-system		\
		-l csfml-audio		\
		-l m			\

CPPFLAGS	=	-I./include

CC	=	gcc

CRIT	=	-l criterion --coverage

MAIN	=	main.c

SRC	=	src/world/world_create.c			\
		src/world/world_reload.c			\
		src/world/world_draw.c				\
		src/world/world_events.c			\
		src/world/world_screenshot.c			\
		src/world/world_quit.c				\
		src/world/world_save.c				\
		src/world/world_loop.c				\
		src/world/world_destroy.c			\
		src/world/world_change_display.c		\
		src/world/world_modify_size.c			\
		src/world/world_set_selection.c			\
								\
		src/sound_effects/sound_effects_create.c	\
		src/sound_effects/sound_effects_destroy.c	\
								\
		src/map/map_create.c				\
		src/map/map_copy.c				\
		src/map/map_load.c				\
		src/map/map_draw.c				\
		src/map/map_destroy.c				\
		src/map/map_colors.c				\
		src/map/map_change_color.c			\
		src/map/map_modify.c				\
		src/map/map_ground_modify.c			\
		src/map/map_water_modify.c			\
								\
		src/keyboard/keyboard_events.c			\
		src/keyboard/keyboard_pressed.c			\
								\
		src/mouse/mouse_events.c			\
		src/mouse/mouse_move_view.c			\
		src/mouse/mouse_hover.c				\
		src/mouse/mouse_select_by_tiles.c		\
		src/mouse/mouse_select_by_corners.c		\
								\
		src/animations/animation_reset.c		\
		src/animations/animation_perlin.c		\
		src/animations/animation_hole.c			\
		src/animations/animation_water_drop.c		\
		src/animations/animation_twisted.c		\
		src/animations/animation_valley.c		\
		src/animations/animation_swapping.c		\
		src/animations/animation_redirect.c		\
		src/animations/animation_screenshot.c		\
								\
		src/menu/menu_create.c				\
	        src/menu/menu_display.c				\
		src/menu/menu_on_off.c				\
	        src/menu/menu_event.c				\
		src/menu/menu_mouse_hover.c			\
		src/menu/menu_destroy.c				\
								\
		src/biomes/biome_create.c			\
								\
		src/help.c					\
								\
		src/load/load_saves.c				\
		src/load/load_loop.c				\
		src/load/load_event.c				\

LIB	=	lib/matrices/matrix_create.c			\
		lib/matrices/matrix_multiply.c			\
		lib/matrices/matrix_rotate.c			\
		lib/matrices/matrix_translate.c			\
		lib/matrices/matrix_scale.c			\
		lib/matrices/matrix_reset.c			\
								\
		lib/fps/fps_create.c				\
		lib/fps/fps_set_font.c				\
		lib/fps/fps_draw.c				\
		lib/fps/fps_set_position.c			\
		lib/fps/fps_destroy.c				\
								\
		lib/get_next_line.c				\
		lib/point_to_2d.c				\
		lib/iso_point.c					\
		lib/line_intersection.c				\
		lib/distance.c					\
								\
		lib/my_rand/perlin.c				\
		lib/my_rand/my_rand.c				\
								\
		lib/button/button_create.c			\
		lib/button/button_on_hold.c			\
		lib/button/button_is_hold.c			\
		lib/button/button_on_click.c			\
		lib/button/button_draw.c			\
		lib/button/button_destroy.c			\
								\
		lib/txt_box/txt_box_create.c			\
		lib/txt_box/txt_box_manage_event.c		\
		lib/txt_box/txt_box_display.c			\
		lib/txt_box/txt_box_destroy.c			\
								\
		lib/create_text.c				\
		lib/shape_create.c				\
								\
		lib/slidebar/slidebar_create.c			\
		lib/slidebar/slidebar_event.c			\
		lib/slidebar/slidebar_display.c			\
		lib/slidebar/slidebar_setvalue.c		\
		lib/slidebar/slidebar_destroy.c			\
								\
		lib/menu_size_map/menu_size_map_create.c	\
		lib/menu_size_map/modify_map_size.c		\
		lib/menu_size_map/menu_size_map_display.c	\
		lib/menu_size_map/menu_size_map_update.c	\
								\
		lib/my_libc/my_str_to_word_array.c		\
		lib/my_libc/my_strcmp.c				\
		lib/my_libc/my_int_to_array.c			\
		lib/my_libc/my_atoi.c				\
		lib/my_libc/my_strdup.c				\
		lib/my_libc/my_strcat.c				\
		lib/my_libc/my_strlen.c				\
		lib/my_libc/my_atof.c				\
		lib/my_libc/my_putfloat.c			\
		lib/my_libc/my_putnbr.c				\
		lib/my_libc/my_puts.c				\

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	my_world

.PHONY:	all
all:	$(NAME)

.PHONY:	$(NAME)
$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

.PHONY:	debug
debug:	CPPFLAGS += -g3
debug:	fclean $(NAME)

.PHONY:	clean
clean:
	-rm $(OBJ)

.PHNOY:	fclean
fclean:	clean
	-rm $(NAME)

.PHONY:	re
re:	fclean all

.PHONY:	tests_run
tests_run:
	$(CC) $(CRIT) $(CPPFLAGS) $(LDFLAGS) $(TESTS) $(SRC) $(LIB) -o ./unit_tests
	./unit_tests
