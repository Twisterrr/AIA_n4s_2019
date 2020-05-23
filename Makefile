##
## EPITECH PROJECT, 2020
## ai
## File description:
## ai
##

NAME	=	ai

CC	=	gcc -o

CFLAGS	=	-L ./lib/my -lm -I./include/

SRC	=	src/main.c	\
		src/move.c	\
		src/utils_move.c \
		src/lidar.c	\
		src/ai.c	\

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:
	$(CC) $(NAME) $(SRC) $(CFLAGS)

clean :
	find -name "*~" -delete , -name "*.o" -delete , -name "#*#" -delete
	rm -f $(OBJ)
	rm -f $(NAME)

fclean : clean
	rm -f $(NAME)

re : fclean all
