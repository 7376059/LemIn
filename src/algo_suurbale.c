/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_suurbale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:21:05 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/08 18:09:49 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
 * int x = 0;
 * if (x != 1 && x = 1)
 * 	printf("+");
 * */

int		get_length(void)
{
	int i;
	int	j;
	
	i = -1;
	j = g_end;
	while (j != -1)
	{
		i++;
		j = g_parent[j];
	}
	return (i);
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
	int 		k;

	i = g_end;
	while (i != -1)
	{
		vertex = graph->vertex;
		j = g_parent[i];

		k = -1;
		while (++k < j)
			vertex = vertex->next;

		if (j != -1)
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
		i = j;
	}
	

	/*while (i != -1)
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
	}*/
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

void	init_path(t_path **path)
{
	int i;
	
	*path = (t_path*)malloc(sizeof(t_path));
	(*path)->max_ways = 100;
	(*path)->max_path = 100;
	(*path)->ways_size = 0;
	(*path)->ways = (int**)malloc(sizeof(int*) * 100);
	i = -1;
	while (++i < 100)
		(*path)->ways[i] = (int*)malloc(sizeof(int) * 100);
}

void	add_way(t_path **path)
{
	int length;
	int i;
	
	//printf("[%d]\n", get_length());
	
	if ((length = get_length()) > (*path)->max_path - 1)
	;//extend_path(path);
	if ((*path)->ways_size == (*path)->max_ways)
	;//extend_ways(path);
	
	(*path)->ways[(*path)->ways_size][0] = length;
	i = g_end;

	while (length != 0)
	{	
		(*path)->ways[(*path)->ways_size][length--] = i;
		i = g_parent[i];
	}
	
	(*path)->ways_size++;
}

void	algo_suurbale(t_graph *graph)
{
	t_path *paths;

	init_path(&paths);
	// while
	//print_graph(graph);

	algo_dijkstra(graph);
	add_way(&paths);
	//add_way
	
	print_way(graph->vector->names);
	
	//add_way(paths); // если дейкстра доработал
	
	//delete edges before modific cost
	
	//print_edges(graph);

	modific_cost(graph->vertex);

	remove_way(graph);

	//print_edges(graph);

	algo_dijkstra(graph);
	print_way(graph->vector->names);
	add_way(&paths);
	remove_way(graph);
	algo_dijkstra(graph);
	print_way(graph->vector->names);
	add_way(&paths);
	
	for (int i = 0; i < 10; i++)
	{
		printf("[%d] ", paths->ways[i][0]);
		for (int j = 1; j < paths->ways[i][0] + 1; j++)
		{
			printf("%d ", paths->ways[i][j]);
		}
		printf("\n");
	}
}
