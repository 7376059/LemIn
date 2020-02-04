# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrady <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 23:32:40 by dgrady            #+#    #+#              #
#    Updated: 2020/02/04 19:44:56 by efriesen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
SRC_NAME = *.c

NAME = lemin

OBJ = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

all :$(NAME)

$(NAME):
	@make re -C ./libft
	@gcc $(FLAGS) -I includes/ -c $(SRC)
	@gcc $(FLAGS) -I includes/ $(OBJ) -o $(NAME) ./libft/libft.a

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all
