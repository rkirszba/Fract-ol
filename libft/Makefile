# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 17:29:25 by rkirszba          #+#    #+#              #
#    Updated: 2019/10/09 12:14:05 by rkirszba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER_PATH = ./includes
HEADER_NAME = libft.h\
			  ft_printf.h\
HEADER = $(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

SRC_PATH = ./src
SRC_NAME = ft_strlen.c \
		   ft_strcmp.c \
		   ft_strncmp.c \
		   ft_strcpy.c \
		   ft_strncpy.c \
		   ft_strdup.c \
		   ft_strstr.c \
		   ft_atoi.c \
		   ft_strcat.c \
		   ft_strncat.c \
		   ft_putchar.c \
		   ft_putchar.c \
		   ft_putstr.c \
	 	   ft_putnbr.c \
		   ft_putendl.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_putnbr_fd.c \
		   ft_strclr.c \
		   ft_isalpha.c \
		   ft_isdigit.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_strnstr.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strchr.c \
		   ft_strrchr.c \
		   ft_memalloc.c \
		   ft_memdel.c \
		   ft_strnew.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strsub.c \
		   ft_strjoin.c \
		   ft_strtrim.c \
		   ft_strsplit.c \
		   ft_itoa.c \
		   ft_dtoa_prec.c \
		   ft_strequ.c \
		   ft_strnequ.c \
		   ft_strdel.c \
		   ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memccpy.c \
		   ft_strlcat.c \
		   ft_lstadd.c \
		   ft_lstdel.c \
		   ft_lstdelone.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_lstnew.c \
		   ft_strccpy.c \
		   ft_lstaddq.c \
		   ft_strrev.c \
		   ft_power.c \
		   ft_swap.c \
		   ft_strcdup.c \
		   ft_iswhitespace.c\
		   ft_memjoin.c\
		   ft_splitdup.c\
		   ft_free_split.c\
		   ft_strsubstitute.c\
		   ft_splitlen.c\
		   ft_percentage.c\
		   ft_printf.c \
		   pf_get.c \
		   pf_itoa.c \
		   pf_padding.c \
		   pf_parse_conv.c \
		   pf_parse_op.c \
		   pf_parse.c \
		   pf_print_c.c \
		   pf_print_di.c \
		   pf_print_error.c \
		   pf_print_ouxxpb.c \
		   pf_print_pct.c \
		   pf_print_s.c \
		   pf_width.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

CC = gcc

CCFLAGS += -Wall \
		  -Wextra \
		  -Werror \

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	@$(CC) $(CCFLAGS) -I$(HEADER_PATH) -c $< -o $@ 

$(NAME): $(OBJ) $(HEADER)
	@ar rc $@ $^
	@ranlib $@
	@echo "made libft"

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

#san: $(OBJ)
#	gcc -g3 -fsanitize=address -o $(NAME) $(OBJ) -I $(HEADER_PATH)


.PHONY: clean re all fclean
