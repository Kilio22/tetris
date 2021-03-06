##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

COLOR_THEME	=	$(BLUE_C)
DEBUG_THEME	=	$(CYAN_C)
TESTS_THEME	=	$(RED_C)

NAME	=	tetris
ROOT_PATH	=	./
SRC_NAME	=	src
TESTS_NAME	=	tests
INCL_NAME	=	include
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)

LOAD_TETRIMIN	=	load_tetriminos
MOD_FUNCTIONS	=	modifier_functions
MENU	=	menu/

SRC	=	$(LOAD_TETRIMIN)/get_tetrimino_piece.c \
		$(LOAD_TETRIMIN)/init_tetrimino.c \
		$(LOAD_TETRIMIN)/is_directory.c \
		$(LOAD_TETRIMIN)/load_tetriminos.c \
		$(LOAD_TETRIMIN)/my_strcat_nofree.c \
		$(LOAD_TETRIMIN)/sort_tetriminos.c	\
		$(MOD_FUNCTIONS)/change_debug.c \
		$(MOD_FUNCTIONS)/change_dropkey.c \
		$(MOD_FUNCTIONS)/change_leftkey.c \
		$(MOD_FUNCTIONS)/change_level.c \
		$(MOD_FUNCTIONS)/change_mapsize.c \
		$(MOD_FUNCTIONS)/change_next.c \
		$(MOD_FUNCTIONS)/change_pausekey.c \
		$(MOD_FUNCTIONS)/change_quitkey.c \
		$(MOD_FUNCTIONS)/change_rightkey.c \
		$(MOD_FUNCTIONS)/change_turnkey.c \
		$(MOD_FUNCTIONS)/function_constants.c \
		$(MOD_FUNCTIONS)/option_constants.c \
		add_tetrimino_to_map.c	\
		analyse_key_pressed.c	\
		check_full_piece.c	\
		debug_mode.c	\
		display_help.c \
		drop_tetrimino.c \
		game_loop.c \
		global_constants.c	\
		highscore_managment.c	\
		init_game.c	\
		$(MENU)init_menu.c	\
		$(MENU)menu_pause.c	\
		$(MENU)menu.c	\
		my_get_line.c	\
		modify_game_props.c	\
		move_left.c	\
		move_right.c	\
		my_set_term.c	\
		utils.c	\
		print_ascii_art.c	\
		print_game_board.c	\
		print_windows.c	\
		remove_full_lines.c	\
		rotate_piece.c	\
		setup_game.c	\
		update_game.c	\
		windows_managment.c

SRC_LIB	=	stdio my string ncurses

LIB_PATHS	=	lib/stdio lib/my lib/string

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.c
OBJ	=	$(SRCS:.c=.o)
LIBRARIES	=	$(SRC_LIB:%=-l%)
LIB_PATHS_FLAG	=	$(LIB_PATHS:%=-L$(ROOT_PATH)%)

CFLAGS	=	-Wall -Wextra -Werror -I $(INCL_PATH)
LDFLAGS	=	$(LIB_PATHS_FLAG) $(LIBRARIES)
DEBUG_FLAGS	=	-g3 -gdwarf-4

MAKE_RULE	=	all
CLEAN_RULE	=	clean

all:	build_libs message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" _____    _        _     "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|_   _|__| |_ _ __(_)___ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  | |/ _ \ __| '__| / __|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)'  | |  __/ |_| |  | \__ \\'$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  |_|\___|\__|_|  |_|___/"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

build_libs: $(LIB_PATHS)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make -C $$MAKE_PATH $(MAKE_RULE) -s ; \
	done

clean_libs: $(LIB_PATHS)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make $(CLEAN_RULE) -C $$MAKE_PATH -s ; \
	done
	@make $(CLEAN_RULE) -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"

clean: clean_libs
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean: CLEAN_RULE=fclean
fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:		fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(DEBUG_THEME)
debug: MAKE_RULE = debug
debug: re
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"⚠ DEBUG MODE ACTIVATED ⚠\n"$(DEFAULT)

tests_run: build_libs
	@make -C $(TESTS_PATH) -s \
		SRC="$(SRC)" \
		COLOR_THEME="$(TESTS_THEME)" \
		LIB_PATHS="$(LIB_PATHS)" \
		LIBRARIES="$(LIBRARIES)"
	@$(ECHO) $(TESTS_THEME)""
	@gcovr --exclude "tests/" --sort-uncovered --branches
	@$(ECHO) $(BOLD_T)""
	@gcovr --exclude "tests/" --sort-uncovered --print-summary
	@$(ECHO) $(DEFAULT)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) build_libs message clean_libs clean fclean re debug tests_run
