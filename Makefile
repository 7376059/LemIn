# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efriesen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 16:49:55 by efriesen          #+#    #+#              #
#    Updated: 2020/02/23 18:07:03 by dgrady           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
BIN = lem-in

_SRC =	algo_suurbale.c\
		algo_dijkstra.c\
		path_functions_1.c\
		path_functions_2.c\
		ants_mover.c\
		balancer.c\
		counter.c\
		edge_vertex.c\
		main.c\
		parser.c\
		stuff.c\
		stuff2.c\
		vector.c

SDIR = sources
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

IDIR = includes
_DEPS = lemin.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

ODIR = objects
_OBJ = $(_SRC:.c=.o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

LDIR = libft
_LIB = libft.a
LIB = $(patsubst %,$(LDIR)/%,$(_LIB))

all: $(BIN)

$(BIN): $(OBJ)
	@make re -C $(LDIR)
	@gcc -o $@ $^ $(LIB) -I $(IDIR)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p objects
	gcc -c -o $@ $< -I $(IDIR)

clean:
	@make clean -C $(LDIR)
	@rm -rf $(ODIR)

fclean: clean
	@rm $(LIB)
	@rm $(BIN)

re: fclean all
