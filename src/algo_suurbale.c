/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_suurbale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:21:05 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/07 21:53:28 by efriesen         ###   ########.fr       */
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

void	remove_list_elem(t_edge **begin, t_edge *remove)
{
	if (remove == NULL)
	{
		printf("ERROR\n");
		exit(0);
	}

	t_edge	*edge;
	t_edge	*prev_edge;

	edge = *begin;
	prev_edge = NULL;

	while (edge != remove)
	{
		prev_edge = edge;
		edge = edge->next;
	}
	
	if (prev_edge == NULL)
		*begin = (*begin)->next;
	else if (edge->next == NULL)
		prev_edge->next = NULL;
	else
		prev_edge->next = edge->next;
	free(edge);
}

void	remove_way(t_graph *graph)
{
	t_vertex	*vertex;
	t_edge		*edge;
	int			i;
	int			j;

	i = g_end;
	while (i != -1)
	{
		vertex = graph->vertex;
		j = -1;
		while (++j < i)
			vertex = vertex->next;
		i = g_parent[i];
		if (i != -1)
		{
			edge = vertex->edges;
			while (edge)
			{
				if (edge->to == i)
					break ;
				edge = edge->next;
			}
			remove_list_elem(&vertex->edges, edge);
		}
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
			edges->cost = edges->cost
				- g_dest[edges->to] + g_dest[vertex->room];
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
	//print_graph(graph);

	algo_dijkstra(graph);
	print_way(graph->vector->names);
	
	//add_way(paths); // если дейкстра доработал
	
	//delete edges before modific cost
	
	//print_edges(graph);

	modific_cost(graph->vertex);

	remove_way(graph);

	//print_edges(graph);

	algo_dijkstra(graph);
	print_way(graph->vector->names);
}
