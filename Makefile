# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 07:30:46 by edvicair          #+#    #+#              #
#    Updated: 2023/03/29 13:27:39 by edvicair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
CFLAGS = -Wall -Wextra -Werror -g
INC = cub3d.h
SRC = 	cub3d.c \
		LIB/Gnl.c \
		LIB/lib.c \
		LIB/lib2.c \
		LIB/utils.c \
		PARSING/check.c \
		PARSING/check2.c \
		PARSING/fill_map.c \
		PARSING/error_map.c \
		PARSING/parsing.c

OBJ=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) #-fsanitize=address
	
%.o: %.c
	gcc -g -o $@ -c $< 

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
