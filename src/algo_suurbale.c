/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_suurbale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:21:05 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/06 19:23:49 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
 * int x = 0;
 * if (x != 1 && x = 1)
 * 	printf("+");
 * */

void	add_way(t_path *paths) // допиливать
{
	int len_way;
	int ver;

	len_way = 0;
	ver = g_end;
	while (ver != -1) 
	{
		len_way++;
		ver = g_parent[ver];
	}
}

void	modific_cost(t_vertex *vertex)
{
	t_edge *edges;

	while (vertex)
	{
		edges = vertex->edges;
		while (edges)
		{
			edges->cost = edges->cost - g_dest[edges->to] + g_dest[vertex->room];
			edges = edges->next;
		}
		vertex = vertex->next;
	}
}

void	algo_suurbale(t_graph *graph)
{
	t_path *paths = (t_path*)malloc(sizeof(t_path));
	paths->size = 0;

	// while
	print_graph(graph);

	algo_dijkstra(graph);
	print_way(graph->vector->names);
	
	//add_way(paths); // если дейкстра доработал
	
	//delete edges before modific cost
	
	modific_cost(graph->vertex);

	print_edges(graph);
}
