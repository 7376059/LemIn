# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efriesen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 20:45:40 by efriesen          #+#    #+#              #
#    Updated: 2020/02/22 19:13:07 by efriesen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/
SRC_NAME = analyze.c\
		   analyze_2.c\
		   flag_modific.c\
		   str_modific.c\
		   str_assembly.c\
		   unsorted_trash.c\
		   ft_itoa_base.c\
		   ft_printf.c\
		   ft_float.c\
		   get_value_from_lst.c

HEADER = ./includes/

LIBFT = ./srcs/libft

NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

all :$(NAME)

$(NAME):
	@gcc -I $(HEADER) -c $(SRC)

clean:
	@rm -f $(SRC_NAME:.c=.o)

fclean: clean
	@rm -f $(NAME)

re : fclean all
