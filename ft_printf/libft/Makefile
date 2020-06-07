# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 20:40:17 by sgertrud          #+#    #+#              #
#    Updated: 2020/06/06 02:36:06 by sgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME=libft
REG_OBJ_FILES = ft_memset.o ft_memcpy.o ft_bzero.o ft_memcmp.o ft_memccpy.o ft_memmove.o\
				ft_putchar_fd.o ft_putnbr_fd_ull.o ft_putstr_fd.o ft_putendl_fd.o\
				ft_strlen.o ft_strchr.o ft_strdup.o ft_strnstr.o ft_strrchr.o\
				ft_strlcat.o ft_strlcpy.o ft_strncmp.o ft_memchr.o ft_substr.o\
				ft_strjoin.o ft_strtrim.o ft_split.o ft_strmapi.o\
				ft_atoi.o ft_itoa.o\
				ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
				ft_tolower.o ft_toupper.o \
				ft_calloc.o

BONUS_OBJ_FILES =	ft_lstnew.o ft_lstadd_front.o ft_lstdelone.o ft_lstsize.o \
					ft_lstadd_back.o ft_lstlast.o ft_lstclear.o ft_lstiter.o ft_lstmap.o \

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)
else
OBJ_FILES = $(REG_OBJ_FILES)
endif

CFLAGS = -Wall -Wextra -Werror

all: $(NAME).a

$(NAME).a : $(OBJ_FILES) libft.h
	ar rc $(NAME).a $?
	ranlib $(NAME).a

%.o: %.c $(NAME).h
	$(CC) -g -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(NAME).a
	rm -f $(NAME).so

re:
	make fclean
	make all
bonus:
	make WITH_BONUS=1 all
so: all bonus
	$(CC)  -shared $(OBJ_FILES) $(BONUS_OBJ_FILES) -o $(NAME).so
.PHONY: all clean fclean re so
