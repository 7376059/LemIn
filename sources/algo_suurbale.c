/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_suurbale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:21:05 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/23 17:44:16 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
 * int x = 0;
 * if (x != 1 && x = 1)
 * 	printf("+");
 * */

// -wall -werror -wextra

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

	// todo: придумать индексам говорящие имена (для vertex то же)
	i = g_end;
	// todo: здесь, вынести -1 в глобальную константу и назвать её (признак отсутствия вершины)
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

void	algo_suurbale(t_graph *graph)
{
	int i = -1;
	
	t_path	*paths;
	t_path	*best_choice;

	init_path(&best_choice);
	init_path(&paths);
	
	while (1)
	{
		algo_dijkstra(graph);
		
		//if (unreachable_vertex()) ... ? 
		//	;

		if (g_dest[g_end] == g_INF)
			break ;
            
		add_way(&paths);
		sort_paths(&paths);
		
		t_path *path;
		path = paths;
		
		paths = counter(paths);
		
		if (best_choice->final_steps == 0 ||
				best_choice->final_steps > paths->final_steps)
			save_best_choice(&best_choice, paths);			
		
		remove_way(graph);
		modific_cost(graph->vertex);
	}
	i	= -1;
	printf ("ants %d\n", g_ants);
	printf ("steps %d\n", best_choice->step_elems);
	while (++i < best_choice->step_elems)
		printf("%d\n", best_choice->steps[i]);
	ants_mover(best_choice, graph->vector->names);
}
