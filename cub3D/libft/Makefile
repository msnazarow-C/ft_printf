# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 20:40:17 by sgertrud          #+#    #+#              #
#    Updated: 2020/10/23 23:28:38 by sgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME=libft.a
SRC = srcs/
OBJ = obj/
INCLUDES = includes
REG_OBJ_FILES = ft_memset.o ft_memcpy.o ft_bzero.o ft_memcmp.o ft_memccpy.o\
				ft_memmove.o\
				ft_putchar_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_putendl_fd.o\
				ft_strlen.o ft_strchr.o ft_strdup.o ft_strnstr.o ft_strrchr.o\
				ft_strlcat.o ft_strlcpy.o ft_strncmp.o ft_memchr.o \
				ft_strjoin.o ft_strtrim.o ft_split.o ft_strmapi.o\
				ft_atoi.o ft_itoa.o\
				ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
				ft_tolower.o ft_toupper.o \
				ft_calloc.o max.o

BONUS_OBJ_FILES =	ft_lstnew.o ft_lstadd_front.o ft_lstdelone.o ft_lstsize.o \
					ft_lstadd_back.o ft_lstlast.o ft_lstclear.o ft_lstiter.o ft_lstmap.o ft_lstconcat.o ft_lstsort.o\

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)
else
OBJ_FILES = $(REG_OBJ_FILES)
endif
D_FILES = $(OBJ_FILES:.o=.d)
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS = --no-print-directory

all: $(OBJ) $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

$(NAME):  $(addprefix $(OBJ),$(OBJ_FILES))
	ar rcs $(NAME) $?

$(OBJ)%.o: $(SRC)%.c
	$(CC) -g -c $(CFLAGS) -I$(INCLUDES) -o $@ $< -MMD

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME:.a=.so)

re:
	make fclean
	make all
bonus:
	make WITH_BONUS=1 all
so:
	$(CC) -fPIC -shared $(OBJ_FILES) $(BONUS_OBJ_FILES) -o libft.so
-include $(addprefix $(OBJ), $(D_FILES))
.PHONY: all clean fclean re so
