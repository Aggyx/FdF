# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:15:12 by smagniny          #+#    #+#              #
#    Updated: 2023/03/25 17:37:03 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS ###
GREEN       = \033[1;32m
CYAN        = \033[1;36m

##COMP
NAME = FdF
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUG = -g -fsanitize=address
SRC_FILES = src/main.c \
	src/mlxplus.c src/init.c src/rdfile.c src/utils.c

OBJS := $(SRC_FILES:%.c=%.o)

##INCLUDES
LIBFT = ./inc/libft/
MLX = ./inc/mlx/


OS := $(shell uname)

ifeq ($(OS),Linux)
    INC := -I./inc/
    LFLAGS := -lX11 -lXext
    LIBS := ./inc/libft/libft.a ./inc/mlx/libmlx_Linux.a
else ifeq ($(OS),Darwin)
	INC := -Imlx
	LFLAGS := -lmlx -framework OpenGL -framework AppKit
	LIBS := ./inc/libft/libft.a
endif


all: $(OBJS)
	@make -C $(LIBFT)
    ifeq ($(OS),Linux)
		@make -C $(MLX)
		$(CC) $(CFLAGS) $(DEBUG) $(OBJS)  -o $(NAME) $(LIBS) $(LFLAGS)
    else ifeq ($(OS),Darwin)
		$(CC) $(CFLAGS) $(DEBUG) $(OBJS) -o $(NAME) $(LIBS) $(LFLAGS)
    endif

free:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(MLX)
	@make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re, fclean, clean, lib, free
