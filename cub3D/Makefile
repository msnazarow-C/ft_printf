# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 20:40:17 by sgertrud          #+#    #+#              #
#    Updated: 2020/10/24 05:58:50 by sgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3D
SRC = srcs/
OBJ = obj/
GNL = get_next_line
INCLUDES = includes
MLX = mlx
OBJ_FILES = bmp.o build_image_utils.o build_image.o parse_line_utils.o\
parse_line.o load_data.o draw_mlx.o errors.o exit_program.o main.o\
handle_events.o draw_sprite.o build_sprite.o init_utils.o init.o \
move_player.o raycasting_engine_utils.o raycasting_engine.o read_input_file.o
LIBFT = libft
UNAME = $(shell uname)
OBJ_OBJ_FILES = $(addprefix $(OBJ),$(OBJ_FILES))
D_FILES = $(patsubst %.o, %.d, $(OBJ_OBJ_FILES))
CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS = --no-print-directory

all: $(OBJ) MKLIB $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

MKLIB:
	make -C $(MLX)
	make bonus -C $(LIBFT)
	make -C $(GNL)

$(NAME): $(LIBFT)/$(LIBFT).a $(GNL)/lib$(GNL).a $(OBJ_OBJ_FILES)
	$(CC) $(CFLAGS) -g $(OBJ_OBJ_FILES) -Iget_next_line/includes -Imlx -Ilibft/includes -Llibft -lft -Lget_next_line -lget_next_line -Iincludes -lmlx -lbsd -L$(MLX) -lXext -lX11 -lm -o $(NAME)

$(OBJ)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -g -c -I$(LIBFT) -I$(INCLUDES) -Imlx -Iget_next_line/includes -Ilibft/includes $(CFLAGS) -o $@ $< -MMD

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT) clean
	make -C $(GNL) clean
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
	rm -f save.bmp
	make -C $(GNL) fclean
	make -C $(LIBFT) fclean
re:
	make -C $(GNL) fclean
	make -C $(LIBFT) fclean
	make -C $(MLX) clean
	make fclean
	make all
bonus:
	make all
include $(wildcard $(D_FILES))
.PHONY: all clean fclean re
