/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dijkstra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:44:17 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/23 16:24:13 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	g_arrays_preparation(int size)
{
	int	i;

	if (g_dest != NULL)
		free(g_dest);
	if (g_parent != NULL)
		free(g_parent);
	if (g_visit != NULL)
		free(g_visit);

	g_dest = (int*)malloc(sizeof(int) * size);
	g_visit = (int*)ft_memalloc(sizeof(int) * size);
	g_parent = (int*)ft_memalloc(sizeof(int) * size);
	g_parent[g_start] = -1; // можно убрать

	i = -1;
	while (++i < size)
		g_dest[i] = g_infinity;
	g_dest[g_start] = 0;
}

void algo_dijkstra(int **matrix, int size_matrix, int *source_vertices)
{
	int	min_dest_vertice;
	int	i;
	int	j;

	g_arrays_preparation(size_matrix);
	i = -1;
	while (++i < size_matrix)
	{
		min_dest_vertice = -1;
		j = -1;
		while (++j < size_matrix)
			if ((g_visit[j] == 0) &&
				(min_dest_vertice == -1 || g_dest[j] < g_dest[min_dest_vertice]))
				min_dest_vertice = j;
		if (g_dest[min_dest_vertice] == g_infinity)
			return ;
		g_visit[min_dest_vertice] = 1;
		j = -1;
		while (++j < size_matrix)
		{
			if (matrix[min_dest_vertice][j] == -1)
				continue ;
			if (g_dest[min_dest_vertice] + matrix[min_dest_vertice][j] < g_dest[j])
			{
				g_dest[j] = g_dest[min_dest_vertice] + matrix[min_dest_vertice][j];
				g_parent[j] = min_dest_vertice;
				//СТРОЧКА НЕ ВЕРНАЯ
				//g_parent[source_vertices[j]] = source_vertices[min_dest_vertice];
			}
		}
	}
}

void	algo_dijkstra_list(t_list_graph *graph)
{
	t_vertex	*in;
	t_edge		*edge;
	int			min;
	int			i;
	int			j;

	// printf("g_dest: ");
	// for (int l = 0; l < graph->vector->elems; l++)
	// 	printf("%d ", g_dest[l]);
	// printf("\n");
	//
	// printf("g_visit: ");
	// for (int l = 0; l < graph->vector->elems; l++)
	// 	printf("%d ", g_visit[l]);
	// printf("\n");
	//
	// printf("g_parent: ");
	// for (int l = 0; l < graph->vector->elems; l++)
	// 	printf("%d ", g_parent[l]);
	// printf("\n\n");

	g_arrays_preparation(graph->vector->elems);

	i = -1;
	while (++i < graph->vector->elems)
	{
		min = -1;
		j = -1;
		while (++j < graph->vector->elems)
			if ((g_visit[j] == 0) && (min == -1 || g_dest[j] < g_dest[min]))
				min = j;
		if (g_dest[min] == g_infinity)
			break ;
		g_visit[min] = 1;
		in = graph->vertex;
		j = -1;
		while (++j < min)
			in = in->next;
		edge = in->edges;
		while (edge)
		{
			if (g_dest[min] + edge->cost < g_dest[edge->to])
			{
				g_dest[edge->to] = g_dest[min] + edge->cost;
				g_parent[edge->to] = min;
			}
			edge = edge->next;
		}
	}

	// printf("g_dest: ");
	// for (int l = 0; l < graph->vector->elems; l++)
	// 	printf("%d ", g_dest[l]);
	// printf("\n");
	//
	// printf("g_visit: ");
	// for (int l = 0; l < graph->vector->elems; l++)
	// 	printf("%d ", g_visit[l]);
	// printf("\n");
	//
	// printf("g_parent: ");
	// for (int l = 0; l < graph->vector->elems; l++)
	// 	printf("%d ", g_parent[l]);
	// printf("\n\n");
}
