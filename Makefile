# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:15:12 by smagniny          #+#    #+#              #
#    Updated: 2023/05/15 13:46:10 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
GREEN       = \033[1;32m
CYAN        = \033[1;36m

#COMP
NAME = FdF
NAMEB = FdF_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
DEBUG = -g
SRC_FILES = src/main.c \
	src/mlxplus.c src/init.c src/rdfile.c src/utils.c src/translate.c src/screenint.c src/EVcontroller.c \
	src/utilsgetcolor.c src/ft_split.c

OBJS = $(SRC_FILES:%.c=%.o)

SRCBONUS_FILES = src_bonus/main_bonus.c \
	src_bonus/mlxplus_bonus.c src_bonus/init_bonus.c src_bonus/rdfile_bonus.c src_bonus/utils_bonus.c src_bonus/translate_bonus.c src_bonus/screenint_bonus.c src_bonus/EVcontroller_bonus.c \
	src_bonus/utilsgetcolor_bonus.c \
	src_bonus/drawrect_bonus.c \
	src_bonus/ft_split.c

OBJS_BONUS = $(SRCBONUS_FILES:%.c=%.o)

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
	@make -sC $(LIBFT)
	@echo  "$(GREEN)Creating libraries files$(CYAN)"
    ifeq ($(OS),Linux)
		@make -sC $(MLX)
		$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) $(LIBS) $(LFLAGS)
    else ifeq ($(OS),Darwin)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) $(LFLAGS)
    endif

clean:
	rm -f $(OBJS)

fclean: clean free
	@rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

free:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make fclean -sC $(LIBFT)

bonus: $(OBJS_BONUS)
	@make -sC $(LIBFT)
	@echo  "$(GREEN)Creating libraries files$(CYAN)"
    ifeq ($(OS),Linux)
		@make -sC $(MLX)
		$(CC) $(CFLAGS) $(OBJS_BONUS)  -o $(NAMEB) $(LIBS) $(LFLAGS)
    else ifeq ($(OS),Darwin)
		$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAMEB) $(LIBS) $(LFLAGS)
    endif

cleanb:
	rm -f $(OBJS_BONUS)

fcleanb: cleanb free
	@rm -f $(NAME)

freelinux:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make fclean -C $(LIBFT)
	@make fclean -C $(MLX)

rebonus: fcleanb bonus

.PHONY: all, clean, fclean, re, free, lib, bonus, cleanb, fcleanb, rebonus