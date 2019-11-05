# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 12:30:08 by rkirszba          #+#    #+#              #
#    Updated: 2019/10/04 11:38:15 by rkirszba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libmlx.a
AR		=	ar rc
RL		=	ranlib

HEADER_PATH = ./includes
HEADER_NAME = libmlx.h

LIB_PATH = ./../libft
LIB_HEADER_NAME = libft.h
LIB_HEADER_PATH = $(addprefix $(LIB_PATH)/, includes)
LIB_NAME = libft.a
LIB_HEADER = $(addprefix $(LIB_HEADER_PATH)/, $(LIB_HEADER_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

SRC_NAME = l_mlx_is_on_plan.c\
		   l_mlx_sub_to_color.c\
		   l_mlx_compute_color.c\
		   l_mlx_color_to_sub.c\
		   l_mlx_write_pixel.c

SRC_PATH = ./src

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)

HEADER = $(addprefix $(HEADER_PATH)/, $(HEADER_NAME))
CFLAGS	=	-Wall -Wextra -Werror -g

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

CC		=	gcc
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -I$(HEADER_PATH) -I$(LIB_HEADER_PATH) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	@$(AR) $@ $^
	@$(RL) $@
	@echo "made libmlx"

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "cleaned libmlx"

fclean: 	clean
	/bin/rm -f $(NAME)
	@echo "fcleaned libmlx"

re:			fclean all

.SILENT:	$(OBJ) $(NAME) all clean fclean re
.PHONY:		all clean fclean re
