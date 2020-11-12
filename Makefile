# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wendell <wendell@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 11:52:28 by gordey            #+#    #+#              #
#    Updated: 2020/11/11 15:14:47 by wendell          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

CFLAGS = 

CC = gcc

MLX = -lmlx -framework OpenGL -framework AppKit

COMP = $(CC) $(CFLAGS) $(INCLUDES)

LIBFT_DIR = libft/
LIBFT_H = -I $(LIBFT_DIR)
LIBFT_A = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_A)

HEAD_DIR = include/
RTV1_H = -I $(HEAD_DIR)
HEAD = $(HEAD_DIR)rtv1.h

INCLUDES = $(LIBFT_H) $(RTV1_H)

SRC_DIR = src/
SRC_FILES =		main.c assignment.c camera.c \
				errors.c figures.c readfile.c readutils.c \
				light1.c \
				setdefault.c color.c light2.c \
				normal.c \
				quadraticequation.c raytrace.c \
				quaterrotation.c draw.c \
				grafic.c utils.c \
				vectors1.c vectors2.c

OBJ_DIR = obj/
OBJ_FILE =	$(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

.PHONY: all clean fclean re

all: lib $(NAME)

lib:
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ) $(HEAD)
	@$(COMP) $(LIBFT) $(MLX) $(OBJ) -o $(NAME)
	@echo "\033[32m \tcompiled \t rtv1 \t\t finish \033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "\033[36m \tmkdir \t\t objects \t finish \033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
	@$(COMP) -c $< -o $@

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "\033[35m \tclean \t\t\t\t finish \033[0m"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "\033[35m \tfclean \t\t\t\t finish \033[0m"

re: fclean all
	@echo "\033[35m \tfclean \t\t all \t\t finish \033[0m"
