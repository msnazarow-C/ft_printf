# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 20:40:17 by sgertrud          #+#    #+#              #
#    Updated: 2020/06/12 00:37:08 by sgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = libftprintf
SRC = srcs/
OBJ = obj/
INCLUDES = includes
OBJ_FILES = printing_utils.o printing.o parsing.o parsing_utils.o \
				lenprint.o print_one.o length_utils.o nbr.o ft_printf.o \
				f_print.o f_len.o f_utils.o
LIBFT = libft


OBJ_OBJ_FILES = $(addprefix $(OBJ),$(OBJ_FILES))
D_FILES = $(patsubst %.o, %.d, $(OBJ_OBJ_FILES))
CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS = --no-print-directory

all: $(OBJ) MKLIB $(NAME).a

$(OBJ):
	mkdir $(OBJ)
MKLIB:
	make -C $(LIBFT)
$(NAME).a: $(LIBFT)/$(LIBFT).a $(OBJ_OBJ_FILES)
	cp $(LIBFT)/$(LIBFT).a ./$(NAME).a
	ar rcs $(NAME).a $(OBJ_OBJ_FILES)

$(OBJ)%.o: $(SRC)%.c
	$(CC) -g -c -I$(LIBFT) -I$(INCLUDES) $(CFLAGS) -o $@ $< -MMD

main : all
	clang -g -Wall -Wextra main.c -L. -Iincludes -Ilibft -lftprintf && ./a.out
clean:
	rm -rf $(OBJ) a.out
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME).a
	rm -f $(NAME).so
	make -C $(LIBFT) fclean
re:
	make -C $(LIBFT) fclean
	make fclean
	make all
bonus:
	make all
include $(wildcard $(D_FILES))
.PHONY: all clean fclean re so
