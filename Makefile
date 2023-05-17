# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:15:12 by smagniny          #+#    #+#              #
#    Updated: 2023/05/17 14:52:34 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
GREEN       = \033[1;32m
CYAN        = \033[1;36m

#COMP
NAME = FdF
NAMEB = FdF_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUG = -g
SRC_FILES = src/main.c \
	src/mlxplus.c src/init.c src/rdfile.c src/translate.c src/screenint.c src/EVcontroller.c \
	src/utilsgetcolor.c

OBJS = $(SRC_FILES:%.c=%.o)

SRCBONUS_FILES = src_bonus/main_bonus.c \
	src_bonus/mlxplus_bonus.c src_bonus/init_bonus.c src_bonus/rdfile_bonus.c src_bonus/translate_bonus.c src_bonus/screenint_bonus.c src_bonus/EVcontroller_bonus.c \
	src_bonus/utilsgetcolor_bonus.c \
	src_bonus/drawrect_bonus.c \

OBJS_BONUS = $(SRCBONUS_FILES:%.c=%.o)

##INCLUDES
LIBFT = ./inc/libft/
MLX = ./inc/mlx/


OS := $(shell uname)

ifeq ($(OS),Linux)
    INC := -I./inc/
    LFLAGS := -lX11 -lXext -lm
    LIBS := ./inc/libft/libft.a ./inc/mlx/libmlx_Linux.a
else ifeq ($(OS),Darwin)
	INC := -Imlx
	LFLAGS := -lmlx -lm -framework OpenGL -framework AppKit
	LIBS := ./inc/libft/libft.a
endif

all: $(OBJS)
	@echo "$(GREEN)Created binary objects"
	@make -sC $(LIBFT)
	@echo  "$(GREEN)Creating libraries files"
    ifeq ($(OS),Linux)
		@make -sC $(MLX)
		@ $(CC) $(CFLAGS) $(OBJS)  -o $(NAME) $(LIBS) $(LFLAGS)
    else ifeq ($(OS),Darwin)
		@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) $(LFLAGS)
	@echo "$(GREEN)Compiled succesfully"
    endif

clean:
	@echo "$(CYAN)Supressing binary objects"
	@rm -f $(OBJS)

fclean: clean free
	@echo "$(CYAN)Supressing binary executable"
	@rm -f $(NAME)

re: fclean all

%.o: %.c
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@

free:
	@echo "$(CYAN)Supressing libraries files"
	@make fclean -sC $(LIBFT)

bonus: $(OBJS_BONUS)
	@echo "$(GREEN)Created bonus binary objects"
	@make -sC $(LIBFT)
	@echo  "$(GREEN)Creating libraries files"
    ifeq ($(OS),Linux)
		@make -sC $(MLX)
		@ $(CC) $(CFLAGS) $(OBJS_BONUS)  -o $(NAMEB) $(LIBS) $(LFLAGS)
    else ifeq ($(OS),Darwin)
		@ $(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAMEB) $(LIBS) $(LFLAGS)
	@echo "$(GREEN)Compiled succesfully"
    endif

cleanb:
	@echo "$(CYAN)Supressing bonus binary objects"
	rm -f $(OBJS_BONUS)

fcleanb: cleanb free
	@echo "$(CYAN)Supressing bonus binary executable"
	@rm -f $(NAME)

freelinux:
	@echo "$(CYAN)Supressing libraries files"
	@make fclean -C $(LIBFT)
	@make fclean -C $(MLX)

rebonus: fcleanb bonus

.PHONY: all, clean, fclean, re, free, lib, bonus, cleanb, fcleanb, rebonus