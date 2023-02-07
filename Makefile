# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:15:12 by smagniny          #+#    #+#              #
#    Updated: 2023/02/06 17:47:05 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

OBJ = main.c \
	src/rdfile.c src/merror.c src/hooks.c src/plusmlx.c

OBJ_O = $(OBJ:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
HFLAGS = -Iinc/utils.h
LFLAGS =  inc/libft/libft.a -lmlx
MLX_FLAGS_MAC = -framework OpenGL -framework AppKit
ERASE = rm

all : $(NAME)

$(NAME): $(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) $(LFLAGS) $(MLX_FLAGS_MAC) -o $(NAME)

clean:
	$(ERASE) $(OBJ_O)

fclean: 
	$(ERASE) $(OBJ_O) $(NAME)
	
re: fclean all
