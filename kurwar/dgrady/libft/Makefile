# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrady <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:16:45 by dgrady            #+#    #+#              #
#    Updated: 2019/11/03 15:10:59 by dgrady           ###   ########.fr        #
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
