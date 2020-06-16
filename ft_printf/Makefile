# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 20:40:17 by sgertrud          #+#    #+#              #
#    Updated: 2020/06/17 02:32:45 by sgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = libftprintf
SRC = srcs/
OBJ = obj/
INCLUDES = includes
OBJ_FILES =  parsing_utils.o nbr.o ft_printf.o \
				f_print.o  f_utils.o f_utils2.o g_len.o
LIBFT = libft
UNAME = $(shell uname)

#ifeq ($(UNAME), Linux)
#OBJ_FILES += lenprint_linux.o parsing_linux.o print_one_linux.o printing_linux.o\
#				printing_utils_linux.o length_utils_linux.o f_len_linux.o
#else
OBJ_FILES += lenprint_mac.o parsing_mac.o print_one_mac.o printing_mac.o\
			printing_utils_mac.o length_utils_mac.o f_len_mac.o
#endif
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
