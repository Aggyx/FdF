# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:15:12 by smagniny          #+#    #+#              #
#    Updated: 2023/03/07 15:03:33 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

##COMP
NAME = FdF
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I./inc/

SRC_PATH = src/

SRC_FILES = main.c \
	my_mlx_pixel_put.c init.c rdfile.c utils.c

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

OBJS = $(SRC:%.c=%.o)

##INCLUDES
LIBFT = ./inc/libft
MLX = ./inc/mlx
LFLAGS = -lX11 -lXext
HEADERS = ./inc/mlx/mlx.h ./inc/libft/libft.h ./inc/utils.h
LIBS = ./inc/libft/libft.a ./inc/mlx/libmlx_Linux.a 


all : lib $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@make -C $(MLX)

$(NAME):  $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)
	@echo "$(GREEN)Supressing object Files"
	@rm $(OBJS)

fclean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -f $(NAME)
	@rm $(OBJS)
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)
	@echo "$(GREEN)Supressing object Files$(CYAN)"
	

re: fclean
	@$(MAKE) all


.PHONY: re, fclean, clean, lib
