/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_suurbale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:21:05 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/12 19:49:50 by efriesen         ###   ########.fr       */
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
	(*path)->size = 0;
	(*path)->final_steps = 0;
	(*path)->ways = (int**)malloc(sizeof(int*) * 100);
	i = -1;
	while (++i < 100)
		(*path)->ways[i] = (int*)malloc(sizeof(int) * 100);
}

void	modific_ways(t_path **path, int i, int j, int k)
{
	for (int i = 0; i < 5; i++)
	{
		printf("[%d] ", (*path)->ways[i][0]);
		for (int j = 1; j < (*path)->ways[i][0] + 1; j++)
			printf("%d ", (*path)->ways[i][j]);
		printf("\n");
	}


	int u;

	u = 0;
	while (i + ++u < (*path)->ways[(*path)->size][0] + 1)
		(*path)->ways[(*path)->size + 1][u]
			= (*path)->ways[(*path)->size][i + u];
	(*path)->ways[(*path)->size + 1][0] = u - 1;

	u = -1;
	while (k + ++u < (*path)->ways[j][0] + 1)
		(*path)->ways[(*path)->size][i + u] = (*path)->ways[j][k + u];
	(*path)->ways[(*path)->size][0] = i + u - 1;	

	u = -1;
	while (++u < (*path)->ways[(*path)->size + 1][0] + 1)
		(*path)->ways[j][k + u - 1] = (*path)->ways[(*path)->size + 1][u + 1];
	(*path)->ways[j][0] = u + k - 3;

	printf("\n");
}

void	detect_common_edge(t_path **path)
{
	int i;
	int	j;
	int	k;

	i = 0;
	while (++i < (*path)->ways[(*path)->size][0] - 1)
	{
		j = -1;
		while (++j < (*path)->size)
		{
			k = 1;
			while (++k < (*path)->ways[j][0])
			{
				if (((*path)->ways[(*path)->size][i] == (*path)->ways[j][k])
						&& ((*path)->ways[(*path)->size][i + 1]
							== (*path)->ways[j][k - 1]))
				{
					modific_ways(path, i + 1, j, k + 1);
					// break ;
				}
			}
		}
	}
}

void	add_way(t_path **path)
{
	int length;
	int i;

	if ((length = get_length()) > (*path)->max_path - 1)
		;//extend_path(path);
	if ((*path)->size == (*path)->max_ways - 1)
		;//extend_ways(path);

	(*path)->ways[(*path)->size][0] = length;
	i = g_end;

	while (length != 0)
	{	
		(*path)->ways[(*path)->size][length--] = i;
		i = g_parent[i];
	}

	detect_common_edge(path);
	(*path)->size++;
}

void	algo_suurbale(t_graph *graph)
{
	t_path *paths;
	t_path	*best_choice;

	print_graph(graph);

	init_path(&paths);
	while (1)
	{
		algo_dijkstra(graph);
		//if (unreachable_vertex()) ... ? 
		//	;

		if (g_dest[g_end] == g_INF)
			break ;

		//print_way(graph->vector->names);

		add_way(&paths);
		remove_way(graph);
		modific_cost(graph->vertex);

		//print_edges(graph);
	}


	for (int i = 0; i < 5; i++)
	{
		printf("[%d] ", paths->ways[i][0]);
		for (int j = 1; j < paths->ways[i][0] + 1; j++)
		{
			printf("%d ", paths->ways[i][j]);
		}
		printf("\n");
	}
}
