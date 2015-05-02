# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/05/02 21:22:03 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes -O3
#--------------Name-------------------------#
NAME = arkanoid

#--------------Sources----------------------#
FILES =	main.c sceneopengl.c parse.c get_next_line.c

OBJECT = $(patsubst %.c,%.o,$(FILES))
OBJ = $(addprefix $(BASEDIR)/, $(OBJECT))
BASEDIR = srcs

CURRENT_DIR = $(shell pwd)/$(NAME)
#--------------Actions----------------------#

all:$(NAME)

$(NAME): $(OBJ)
	git submodule init
	git submodule update
#	cd ./glfw;ccmake -DCMAKE_INSTALL_PREFIX:PATH=~/glfw .;make install
	make -C libft
	@$(CC) -o $(NAME) libft/libft.a $(OBJ) -I ~/glfw/include -L ~/glfw/lib -lglfw -framework OpenGL -I ./includes -I ./glfw/deps/

%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) -I ~/glfw/include -I ./includes -I ./glfw/deps/ $<
	@git submodule update

clean:
		rm -Rf $(OBJ)

fclean: clean
		rm -Rf $(NAME)
		rm -rf glfw
		rm -rf libft/libft.a

re: fclean all

.PHONY: all, fclean, clean, re 

