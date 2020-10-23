# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 20:40:17 by sgertrud          #+#    #+#              #
#    Updated: 2020/10/23 23:26:58 by sgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libget_next_line.a
SRC = srcs/
OBJ = obj/
INCLUDES = includes
OBJ_FILES = get_next_line.o get_next_line_utils.o
D_FILES = $(OBJ_FILES:.o=.d)
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS = --no-print-directory

all: $(OBJ) $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

$(NAME): $(addprefix $(OBJ),$(OBJ_FILES))
	ar rcs $(NAME) $?

$(OBJ)%.o: $(SRC)%.c #$(OBJ)
	$(CC) -g -c $(CFLAGS) -I$(INCLUDES) -o $@ $< -MMD

clean:
	rm -rf $(OBJ)
	#rm -f $(addprefix $(OBJ),$(OBJ_FILES))

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all
bonus:
	make WITH_BONUS=1 all
-include $(addprefix $(OBJ), $(D_FILES))
.PHONY: all clean fclean re so
