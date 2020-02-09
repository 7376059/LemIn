# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrady <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:16:45 by dgrady            #+#    #+#              #
#    Updated: 2020/01/19 13:55:03 by dgrady           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
SOURCES    = *.c 
OBJECTS    = *.o 
FLAGS       = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SOURCES) -I includes/
	@ar rc libft.a $(OBJECTS)
	@ranlib libft.a

clean:
	@/bin/rm -f $(OBJECTS)
fclean: clean
	@/bin/rm -f  $(NAME)
re: fclean all
