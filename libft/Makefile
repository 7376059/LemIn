# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efriesen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 21:21:49 by efriesen          #+#    #+#              #
#    Updated: 2020/03/12 23:47:20 by efriesen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/
SRC_NAME = ft_atoi.c\
		   ft_itoa.c\
		   ft_putchar.c\
		   ft_putnbr.c\
		   ft_putstr.c\
		   ft_isalpha.c\
		   ft_isdigit.c\
		   ft_strcmp.c\
		   ft_strncmp.c\
		   ft_strdup.c\
		   ft_strcpy.c\
		   ft_strncpy.c\
		   ft_strstr.c\
		   ft_strequ.c\
		   ft_strnequ.c\
		   ft_strchr.c\
		   ft_strrchr.c\
		   ft_strlen.c\
		   ft_strsplit.c\
		   ft_arrstr_clr.c\
		   ft_strjoin.c\
		   ft_strjoin_char.c\
		   ft_memalloc.c\
		   get_next_line.c

SRC_PRINTF_PATH = ./ft_printf/
_SRC_PRINTF = analyze.c\
			 analyze_2.c\
			 flag_modific.c\
			 str_modific.c\
			 str_assembly.c\
			 unsorted_trash.c\
			 ft_itoa_base.c\
			 ft_printf.c\
			 ft_float.c\
			 get_value_from_lst.c

SRC_PRINTF = $(addprefix $(SRC_PRINTF_PATH), $(_SRC_PRINTF))

HEADER = ./includes/

NAME = libft.a

OBJ = $(SRC_NAME:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

all: $(NAME)

$(NAME):
	@make -C ft_printf
	@gcc -c -Wall -Wextra -Werror $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ) $(OBJ_PRINTF)
	@ranlib $(NAME)

clean:
	@make clean -C ft_printf
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
