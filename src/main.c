/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:27:51 by dgrady            #+#    #+#             */
/*   Updated: 2020/02/04 19:09:48 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// lem_in exec

void	print_graph(t_graph *gr)
{
	print_names(gr);

	printf("\nstart_room  = %d\nend_room = %d\n", g_start, g_end);
	printf("\nsize = %d\nelems = %d\n\n", gr->vector->size, gr->vector->elems);

	print_edges(gr);

	printf("\nFinito La Comedia\n");
}

int main(void)
{	
	g_start = -1;
	g_end = -1;

	t_graph *gr = init_graph();
	gr = start_parser(gr);

	print_graph(gr);

	algo_dijkstra(gr);

	return (0);
}
