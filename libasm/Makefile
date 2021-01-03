# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 20:40:17 by sgertrud          #+#    #+#              #
#    Updated: 2020/11/04 13:12:14 by sgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re main bonus
CC = gcc
NAME = libasm.a
SRC = srcs/
OBJ = obj/
INCLUDES = includes
OBJ_FILES = ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o
BONUS_FILES = ft_atoi_base.o ft_list_push_front.o ft_list_size.o ft_list_sort.o \
				ft_list_remove_if.o ft_atoi_base_bonus.o
LIBFT = libft
UNAME = $(shell uname)
REG_OBJ_FILES = $(addprefix $(OBJ),$(OBJ_FILES))
BONUS_OBJ_FILES = $(addprefix $(OBJ),$(BONUS_FILES))
CFLAGS = -g -Wall -Wextra -Werror
ASMFLAGS = -f elf64 -g -F dwarf
MAKEFLAGS = --no-print-directory
ifdef WITH_BONUS
OBJ_OBJ_FILES = $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)
else
OBJ_OBJ_FILES = $(REG_OBJ_FILES)
endif

all: $(OBJ) $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

$(NAME): $(OBJ_OBJ_FILES)
	ar rcs $@ $?

main: bonus
	$(CC) $(CFLAGS) -I$(INCLUDES) main.c strings_check.c -L. -lasm && ./a.out

$(OBJ)%.o: $(SRC)%.s
	nasm $(ASMFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -f write.txt
	rm -f $(NAME)
	rm -f ./a.out
re:
	make fclean
	make WITH_BONUS=1 all
bonus:
	make WITH_BONUS=1 all
