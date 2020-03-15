/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_suurbale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:21:05 by efriesen          #+#    #+#             */
/*   Updated: 2020/03/15 18:00:34 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph	*set_default_values(t_graph *graph)
{
	int	i;
	int	j;

	i = -1;
	while (++i < graph->max_size_matrix)
	{
		j = -1;
		while (++j < graph->max_size_matrix)
		{
			graph->adjacency_matrix[i][j] = -1;
			graph->links_in_matrix[i][j] = 0;
		}
	}
	return (graph);
}

t_graph	*allocate_graph(int amt_vertices)
{
	t_graph	*graph;
	int		i;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->elems_in_matrix = amt_vertices;
	graph->amount_vertices = amt_vertices;
	graph->max_size_matrix = amt_vertices * 2;
	graph->source_vertices = (int*)ft_memalloc(sizeof(int) * amt_vertices * 2);
	i = -1;
	while (++i < amt_vertices)
		graph->source_vertices[i] = i;
	graph->duplicated_vertices = (int*)ft_memalloc(sizeof(int) * amt_vertices);
	graph->adjacency_matrix =
		(int**)malloc(sizeof(int*) * amt_vertices * 2);
	graph->links_in_matrix =
		(int**)malloc(sizeof(int*) * amt_vertices * 2);
	i = -1;
	while (++i < amt_vertices * 2)
	{
		graph->adjacency_matrix[i] =
			(int*)malloc(sizeof(int) * amt_vertices * 2);
		graph->links_in_matrix[i] =
			(int*)malloc(sizeof(int) * amt_vertices * 2);
	}
	return (set_default_values(graph));
}

t_graph	*init_graph(t_list_graph *list_graph)
{
	t_vertex	*vertex;
	t_graph		*graph;
	t_edge		*edges;
	int			i;

	graph = allocate_graph(list_graph->vector->elems);
	vertex = list_graph->vertex;
	while (vertex)
	{
		i = 1;
		edges = vertex->edges;
		while (edges)
		{
			if (graph->adjacency_matrix[vertex->room][edges->to] == -1)
			{
				graph->adjacency_matrix[vertex->room][edges->to] = edges->cost;
				graph->links_in_matrix[vertex->room][0]++;
				graph->links_in_matrix[vertex->room][i++] = edges->to;
			}
			edges = edges->next;
		}
		vertex = vertex->next;
	}
	return (graph);
}

void	algo_suurbale(t_graph *graph, t_path *paths, t_path *best_choice)
{
	while (1)
	{
		algo_dijkstra(graph->links_in_matrix, graph->adjacency_matrix,
			graph->elems_in_matrix);
		if (g_dest[g_end] == g_infinity)
			break ;
		add_way(paths, graph->source_vertices);
		sort_paths(paths);
		counter(paths);
		if (best_choice->final_steps == 0 ||
				best_choice->final_steps > paths->final_steps)
			save_best_choice(best_choice, paths);
		modify_and_remove_edges(graph->links_in_matrix, graph->adjacency_matrix,
			graph->elems_in_matrix);
		duplicate_vertices_in_shortest_way(graph, graph->links_in_matrix,
			graph->adjacency_matrix);
	}
}

void	algorithm_suurbale(t_graph *graph, char **vertices_names,
		char *graph_output)
{
	t_path	*paths;
	t_path	*best_choice;

	init_path(&best_choice);
	init_path(&paths);
	algo_suurbale(graph, paths, best_choice);
	if (!paths->size)
		invalid_graph();
	if (g_print_paths)
		print_paths(paths, best_choice, vertices_names);
	else
		ants_mover(best_choice, vertices_names, graph_output);
	clear_graph(graph);
	clear_path(paths);
	clear_path(best_choice);
	free(g_dest);
	free(g_parent);
	free(g_visit);
}
