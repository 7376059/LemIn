/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurbale_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:11:50 by efriesen          #+#    #+#             */
/*   Updated: 2020/03/15 18:02:35 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	remove_link(int **links, int v, int to)
{
	int i;

	i = 0;
	while (++i <= links[v][0])
		if (links[v][i] == to)
			break ;
	if (i != links[v][0])
		links[v][i] = links[v][links[v][0]];
	links[v][0]--;
}

void	remove_shortest_way(int **links, int **matrix)
{
	int	to;
	int v;

	to = g_end;
	v = g_parent[to];
	while (v != -1)
	{
		matrix[v][to] = -1;
		remove_link(links, v, to);
		matrix[to][v] = 0;
		to = v;
		v = g_parent[to];
	}
}

void	modify_and_remove_edges(int **links, int **matrix, int size_matrix)
{
	int i;
	int j;

	i = -1;
	while (++i < size_matrix)
	{
		j = 0;
		while (++j <= links[i][0])
			matrix[i][links[i][j]] =
				matrix[i][links[i][j]] - g_dest[links[i][j]] + g_dest[i];
	}
	remove_shortest_way(links, matrix);
}

void	duplicating_vertice(t_graph *graph, int duplicate_vertice,
		int next_vertice, int previous_vertice)
{
	int **matrix;
	int **links;
	int i;

	matrix = graph->adjacency_matrix;
	links = graph->links_in_matrix;
	remove_link(links, duplicate_vertice, next_vertice);
	matrix[duplicate_vertice][graph->elems_in_matrix] = 0;
	links[duplicate_vertice][0]++;
	links[duplicate_vertice][links[duplicate_vertice][0]] =
		graph->elems_in_matrix;
	i = -1;
	while (++i < graph->amount_vertices)
	{
		if (matrix[i][duplicate_vertice] == -1 || i == previous_vertice)
			continue ;
		matrix[i][graph->elems_in_matrix] = matrix[i][duplicate_vertice];
		links[i][0]++;
		links[i][links[i][0]] = graph->elems_in_matrix;
		matrix[i][duplicate_vertice] = -1;
		remove_link(links, i, duplicate_vertice);
	}
	graph->source_vertices[graph->elems_in_matrix] = duplicate_vertice;
	graph->elems_in_matrix++;
}

void	duplicate_vertices_in_shortest_way(t_graph *graph, int **links,
	int **matrix)
{
	int duplicate_vertice;
	int	previous_vertice;
	int	next_vertice;

	previous_vertice = g_end;
	duplicate_vertice = g_parent[previous_vertice];
	next_vertice = g_parent[duplicate_vertice];
	while (next_vertice != -1)
	{
		if (graph->duplicated_vertices
			[graph->source_vertices[duplicate_vertice]] == 0)
		{
			graph->duplicated_vertices[duplicate_vertice] = 1;
			matrix[graph->elems_in_matrix][next_vertice] =
				matrix[duplicate_vertice][next_vertice];
			links[graph->elems_in_matrix][0] = 1;
			links[graph->elems_in_matrix][1] = next_vertice;
			matrix[duplicate_vertice][next_vertice] = -1;
			duplicating_vertice(graph, duplicate_vertice,
				next_vertice, previous_vertice);
		}
		previous_vertice = duplicate_vertice;
		duplicate_vertice = next_vertice;
		next_vertice = g_parent[duplicate_vertice];
	}
}
