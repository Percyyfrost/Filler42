# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vuyaninxele <marvin@42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 18:52:32 by vuyaninxe         #+#    #+#              #
#    Updated: 2018/08/20 14:30:54 by vnxele           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c

NAME = res/players/vnxele.filler

LIB = -L libft -lft

FLAGS = -Wall -Werror -Wextra

SRC = filler.c play.c droid.c helper_ft.c en_pos.c

OBJ = filler.o play.o droid.o helper_ft.o en_pos.o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@clang $(SRC) $(LIB) -o $(NAME) $(FLAGS)
	 
clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm $(NAME)

re: fclean all
