##
## EPITECH PROJECT, 2019
## minishell2
## File description:
## Makefile
##

SRC	=	game.c			\
		my_event.c		\
		background.c		\
		clock_function.c	\
		music.c			\
		sprite_animation.c	\
		mouse_func.c		\
		main.c			\
		help.c			\
		display_text.c		\
		destroy_item.c		\
		lib/my/my_strcpy.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strdup.c	\
		lib/my/my_revstr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c

OBJ     =       $(SRC:.c=.o)

GRAPH	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS  =       -W -Wall -Wextra -g -I./include

NAME    =       my_hunter

all:            $(OBJ)
		gcc -o $(NAME) $(OBJ) $(GRAPH)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
