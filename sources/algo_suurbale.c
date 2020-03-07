/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_suurbale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:21:05 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/23 19:59:53 by efriesen         ###   ########.fr       */
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

void	remove_way_list(t_list_graph *graph)
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



void	modific_cost_list(t_vertex *vertex)
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

void	clear_path(t_path *paths)
{
	clear_int_array(paths->ways, paths->size);
	free(paths->steps);
	free(paths);
}

void	clear_all(t_path *path, t_path *best)
{
	clear_path(best);
	clear_path(path);

	free(g_dest);
	free(g_parent);
	free(g_visit);
}

void print_ways(t_path *path, char **names)
{
	for (int i = 0; i < path->size; i++)
	{
			printf("[%d] : ", path->ways[i][0]);
			for (int j = 1; j <= path->ways[i][0]; j++)
				printf("%s ", names[path->ways[i][j]]);
			printf("\n");
	}
	printf("\n");
}

t_graph	*init_graph(t_list_graph *list_graph)
{
	t_vertex	*vertex;
	t_graph		*graph;
	t_edge		*edges;
	int				i;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->elems_in_matrix = list_graph->vector->elems;
	graph->amount_vertices = list_graph->vector->elems;
	graph->max_size_matrix = list_graph->vector->elems * 2;

	graph->source_vertices = (int*)ft_memalloc(sizeof(int) * graph->max_size_matrix);
	i = -1;
	while (++i < graph->amount_vertices)
		graph->source_vertices[i] = i;

	graph->duplicated_vertices = (int*)ft_memalloc(sizeof(int) * graph->amount_vertices);

	graph->adjacency_matrix =
		(int**)malloc(sizeof(int*) * graph->max_size_matrix);

	i = -1;
	while (++i < graph->max_size_matrix)
		graph->adjacency_matrix[i] =
			(int*)malloc(sizeof(int) * graph->max_size_matrix);

	int j;
	i = -1;
	while (++i < graph->max_size_matrix)
	{
		j = -1;
		while (++j < graph->max_size_matrix)
			graph->adjacency_matrix[i][j] = -1;
	}

	vertex = list_graph->vertex;
	while (vertex)
	{
		edges = vertex->edges;
		while (edges)
		{
			graph->adjacency_matrix[vertex->room][edges->to] = edges->cost;
			edges = edges->next;
		}
		vertex = vertex->next;
	}

	return (graph);
}

void print_matrix(t_graph *graph, char **names)
{
	printf("     ");
	for (int i = 0; i < graph->elems_in_matrix; i++)
		printf("[%s] ", names[graph->source_vertices[i]]);
	printf("\n");
	for (int i = 0; i < graph->elems_in_matrix; i++)
	{
		printf("[%s] ", names[graph->source_vertices[i]]);
		for (int j = 0; j < graph->elems_in_matrix; j++)
		{
			if (graph->adjacency_matrix[i][j] == -1)
				printf("%3d ", graph->adjacency_matrix[i][j]);
			else
				printf("[%d] ", graph->adjacency_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void remove_shortest_way(int **matrix, int size_matrix)
{
	int	to;
	int v;

	to = g_end;
	v = g_parent[to];
	while (v != -1)
	{
		matrix[v][to] = -1;
		matrix[to][v] = 0;
		to = v;
		v = g_parent[to];
	}
}

void modify_and_remove_edges(int **matrix, int size_matrix)
{
	int i;
	int j;

	i = -1;
	while (++i < size_matrix)
	{
		j = -1;
		while (++j < size_matrix)
		{
			if (matrix[i][j] == -1)
				continue ;
			matrix[i][j] = matrix[i][j] - g_dest[j] + g_dest[i];
		}
	}
	remove_shortest_way(matrix, size_matrix);
}

void duplicate_vertices_in_shortest_way(t_graph *graph, int **matrix, int amount_vertices)
{
	int duplicate_vertice;
	int	previous_vertice;
	int	next_vertice;
	int	i;

	previous_vertice = g_end;
	duplicate_vertice = g_parent[previous_vertice];
	next_vertice = g_parent[duplicate_vertice];

	while (next_vertice != -1) // while (g_parent[vertice] != -1)
	{
		// printf("prev: %d\n", previous_vertice);
		// printf("curr: %d\n", duplicate_vertice);
		// printf("next: %d\n\n", next_vertice);

		if (graph->duplicated_vertices[graph->source_vertices[duplicate_vertice]] == 0)
		{
			graph->duplicated_vertices[duplicate_vertice] = 1;

			matrix[graph->elems_in_matrix][next_vertice] = matrix[duplicate_vertice][next_vertice];
			matrix[duplicate_vertice][next_vertice] = -1;
			matrix[duplicate_vertice][graph->elems_in_matrix] = 0;

			i = -1;
			while (++i < amount_vertices)
			{
				if (matrix[i][duplicate_vertice] == -1 || i == previous_vertice)
					continue ;
				matrix[i][graph->elems_in_matrix] = matrix[i][duplicate_vertice];
				matrix[i][duplicate_vertice] = -1;
			}

			graph->source_vertices[graph->elems_in_matrix] = duplicate_vertice;
			graph->elems_in_matrix++;
		}

		previous_vertice = duplicate_vertice;
		duplicate_vertice = next_vertice;
		next_vertice = g_parent[duplicate_vertice];
	}
}

void	algo_suurbale(t_list_graph *list_graph)
{
	t_path	*paths;
	t_path	*best_choice;
	t_graph	*graph;

	graph = init_graph(list_graph);

	init_path(&best_choice);
	init_path(&paths);

	g_dest = NULL;
	g_parent = NULL;
	g_visit = NULL;
	g_infinity = 1000000000;

	while (1)
	{
		algo_dijkstra(graph->adjacency_matrix, graph->elems_in_matrix, graph->source_vertices);

		// for (int i = g_end; i != -1;)
		// {
		// 	printf("%s ", list_graph->vector->names[graph->source_vertices[i]]);
		// 	i = g_parent[i];
		// }
		// printf("\n");

			// for (int i = 0; i < graph->elems_in_matrix; i++)
			// 	printf("%d ", g_dest[i]);
			// printf("\n");

		// for (int i = 0; i < graph->elems_in_matrix; i++)
		// 		printf("%d ", g_parent[i]);
		// printf("\n");

		//algo_dijkstra_list(list_graph);

		//if (unreachable_vertex()) ... ?
		//	;

		if (g_dest[g_end] == g_infinity)
			break ;

		//add_way_test(paths, graph->source_vertices);
		add_way(&paths, graph->source_vertices);

		//print_ways(paths, list_graph->vector->names);

		// заменить двойные указатели
		sort_paths(&paths); // что-то тут он крутит хуютит

		paths = counter(paths); //  нахуй .. ?

		if (best_choice->final_steps == 0 ||
				best_choice->final_steps > paths->final_steps)
			save_best_choice(&best_choice, paths); // двойной указатель убрать можно .. ?

		// print_matrix(graph, list_graph->vector->names);
		//remove_way_list(list_graph);

	  modify_and_remove_edges(graph->adjacency_matrix, graph->elems_in_matrix);
		// print_matrix(graph, list_graph->vector->names);

		duplicate_vertices_in_shortest_way(graph, graph->adjacency_matrix, graph->amount_vertices);
		//modific_cost_list(list_graph->vertex);
		// print_matrix(graph, list_graph->vector->names);


		// for (int i = 0; i < graph->elems_in_matrix; i++)
		//  printf("%d ", graph->source_vertices[i]);
		// printf("\n");

		// printf("------------------------\n\n");
		//exit(0);
	}

	//print_ways(paths, list_graph->vector->names);
	ants_mover(best_choice, list_graph->vector->names);
	clear_all(paths, best_choice);
}
