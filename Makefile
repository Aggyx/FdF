# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:15:12 by smagniny          #+#    #+#              #
#    Updated: 2022/12/12 19:00:45 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

OBJ = main.c \
	src/my_mlx_pixel_put.c src/init.c src/rdfile.c

OBJ_O = $(OBJ:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
HFLAGS = inc/utils.h
LFLAGS = -Linc/libft/ -Linc/mlx/ -llibft -llibmlx
MLX_FLAGS_MAC = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) $(HFLAGS) inc/libft/libft.a inc/mlx/libmlx.a $(MLX_FLAGS_MAC)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

