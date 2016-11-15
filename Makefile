# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:51:08 by fhenry            #+#    #+#              #
#    Updated: 2016/10/21 16:37:21 by fhenry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fhenry.filler

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_PATH = src/
OBJ_PATH = obj/
LIB_PATH = libft/
INC_PATH = includes/

SRC_NAME = main.c \
		   parsing.c \
		   find_size_and_ref.c \
		   place_forme.c \
		   check_map.c \
		   find_first_position.c \
		   farest_point.c \
		   find_the_farest.c \
		   ft_free_tab.c \
		   check_every_place.c \
		   end_while.c \
		   init_env.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIB_PATH)libft.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@$(MAKE) -C $(LIB_PATH) $@

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_PATH) $@

re: fclean all
