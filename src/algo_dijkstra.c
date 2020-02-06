/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dijkstra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:44:17 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/06 19:13:53 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// malloc error .. ?
// free

// недостижимые вершины 

// кол-во муравьев меньше кратчайшего пути

// алгоритм суурбале не до конца

// дейкстра брейкнулся => путей нет, суурбале стоп

void	create_arr(int size)
{
	// free
	int	i;
	
	g_INF = 10000000;
	g_dest = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		g_dest[i] = g_INF;
	g_dest[g_start] = 0;
	g_parent = (int*)ft_memalloc(sizeof(int) * size);
	g_parent[g_start] = -1;
	g_visit = (int*)ft_memalloc(sizeof(int) * size);
}

void	algo_dijkstra(t_graph *graph)
{
	t_vertex	*in;
	t_edge		*edge;
	int			min;
	int			i;
	int			j;

	create_arr(graph->vector->elems);
	
	i = -1;
	while (++i < graph->vector->elems)
	{
		min = -1;
		j = -1;
		while (++j < graph->vector->elems)
			if ((g_visit[j] == 0) && (min == -1 || g_dest[j] < g_dest[min]))
				min = j;
		if (g_dest[min] == g_INF)
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
}
