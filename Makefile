# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 13:10:40 by bmenant           #+#    #+#              #
#    Updated: 2019/06/04 14:57:35 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_FILE = ./src/
OBJ_FILE = ./obj/

SRCS = fdf_count_numbers.c \
	   fdf_define_color.c \
	   fdf_define_image.c \
	   fdf_define_line.c \
	   fdf_free_and_exit.c \
	   fdf_key_handler.c \
	   fdf_mouse_handler.c \
	   fdf_parser.c \
	   fdf_print_line.c \
	   fdf_put_instructions.c \
	   main.c 

OBJS = $(SRCS:.c=.o)

SRC = $(addprefix $(SRC_FILE),$(SRCS))
OBJ = $(addprefix $(OBJ_FILE),$(OBJS))

FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I./includes/
LFLAGS = ./libft/libft.a

CC = gcc $(CFLAGS)

.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME) : $(OBJ)
	@ make -C./libft/
	@ $(CC) $(LFLAGS) $(OBJ) -o $@ $(FLAGS)

$(OBJ_FILE)%.o : $(SRC_FILE)%.c
	@ mkdir $(OBJ_FILE) 2> /dev/null || true
	@ $(CC) $(IFLAGS) -o $@ -c $<

clean :
	@ make clean -C ./libft/
	@ rm -f $(OBJ)
	@ rmdir $(OBJ_FILE) 2> /dev/null || true

fclean : clean
	@ make fclean -C ./libft/
	@ rm -f $(NAME)

re	: fclean all

test : re
	@ ./fdf maps/basictest.fdf

norme :
	@ norminette $(SRC)
