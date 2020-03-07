/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:53:40 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/17 17:11:24 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	extend_path(t_path **path, int new_size)
{
	int **extended_ways;
	int i;
	int j;

	extended_ways = (int**)malloc(sizeof(int*) * (*path)->max_ways);
	i = -1;
	while (++i < (*path)->max_ways)
		extended_ways[i] = (int*)malloc(sizeof(int) * new_size);
	i = -1;
	while (++i < (*path)->size)
	{
		j = -1;
		while (++j < (*path)->ways[i][0] + 1)
			extended_ways[i][j] = (*path)->ways[i][j];
		free((*path)->ways[i]);
	}
	free((*path)->ways);
	(*path)->ways = extended_ways;
	(*path)->max_path = new_size;
}

void	extend_ways(t_path **path, int new_size)
{
	int **extended_ways;
	int i;
	int j;

	extended_ways = (int**)malloc(sizeof(int*) * new_size);
	i = -1;
	while (++i < new_size)
		extended_ways[i] = (int*)malloc(sizeof(int) * (*path)->max_path);
	i = -1;
	while (++i < (*path)->size)
	{
		j = -1;
		while (++j < (*path)->ways[i][0] + 1)
			extended_ways[i][j] = (*path)->ways[i][j];
		free((*path)->ways[i]);
	}
	free((*path)->ways);
	(*path)->ways = extended_ways;
	(*path)->max_ways = new_size;
}

void	extend_path_test(t_path *path, int new_size)
{
	int **extended_ways;
	int i;
	int j;

	extended_ways = (int**)malloc(sizeof(int*) * path->max_ways);
	i = -1;
	while (++i < path->max_ways)
		extended_ways[i] = (int*)malloc(sizeof(int) * new_size);
	i = -1;
	while (++i < path->size)
	{
		j = -1;
		while (++j < path->ways[i][0] + 1)
			extended_ways[i][j] = path->ways[i][j];
		free(path->ways[i]);
	}
	free(path->ways);
	path->ways = extended_ways;
	path->max_path = new_size;
}

void	extend_ways_test(t_path *path, int new_size)
{
	int **extended_ways;
	int i;
	int j;

	extended_ways = (int**)malloc(sizeof(int*) * new_size);
	i = -1;
	while (++i < new_size)
		extended_ways[i] = (int*)malloc(sizeof(int) * path->max_path);
	i = -1;
	while (++i < path->size)
	{
		j = -1;
		while (++j < path->ways[i][0] + 1)
			extended_ways[i][j] = path->ways[i][j];
		free(path->ways[i]);
	}
	free(path->ways);
	path->ways = extended_ways;
	path->max_ways = new_size;
}

// int		get_length(void)
// {
// 	int i;
// 	int j;
//
// 	i = -1;
// 	j = g_end;
// 	while (j != -1)
// 	{
// 		i++;
// 		j = g_parent[j];
// 	}
// 	return (i);
// }

int		get_length_way(int *source_vertices)
{
	int previous_vertice;
	int current_vertice;
	int length_way;

	length_way = 0;
	previous_vertice = g_end;
	current_vertice = g_parent[previous_vertice];

	while (current_vertice != -1)
	{
		if (source_vertices[current_vertice] != source_vertices[previous_vertice])
			length_way++;

		previous_vertice = current_vertice;
		current_vertice = g_parent[previous_vertice];
	}
	return (length_way);
}

void add_way_test(t_path *path, int *source_vertices)
{
	int previous_vertice;
	int current_vertice;
	int length_way;

	while ((length_way = get_length_way(source_vertices)) > path->max_path - 1)
		extend_path_test(path, 2 * path->max_path);
	while (path->size >= path->max_ways - 1)
		extend_ways_test(path, 2 * path->max_ways);
	path->ways[path->size][0] = length_way;
	previous_vertice = g_end;
	current_vertice = g_parent[previous_vertice];
	while (length_way != 0)
	{
		if (source_vertices[current_vertice] != source_vertices[previous_vertice])
			path->ways[path->size][length_way--] = source_vertices[previous_vertice];

		previous_vertice = current_vertice;
		current_vertice = g_parent[previous_vertice];
	}
	//detect_common_edge(path);
	path->size++;
}

void	add_way(t_path **path, int *source_vertices)
{
	int previous_vertice;
	int current_vertice;
	int length_way;

	while ((length_way = get_length_way(source_vertices)) > (*path)->max_path - 1)
		extend_path(path, 2 * (*path)->max_path);
	while ((*path)->size >= (*path)->max_ways - 1)
		extend_ways(path, 2 * (*path)->max_ways);
	(*path)->ways[(*path)->size][0] = length_way;
	previous_vertice = g_end;
	current_vertice = g_parent[previous_vertice];
	while (length_way != 0)
	{
		if (source_vertices[current_vertice] != source_vertices[previous_vertice])
			(*path)->ways[(*path)->size][length_way--] = source_vertices[previous_vertice];

		previous_vertice = current_vertice;
		current_vertice = g_parent[previous_vertice];
	}
	detect_crossing_paths(*path); // **
	//detect_common_edge(path);
	(*path)->size++;
}

// void	add_way(t_path **path, int *source_vertices)
// {
// 	int previous_vertice;
// 	int length;
// 	int i;
//
// 	while ((length = get_length(source_vertices)) > (*path)->max_path - 1)
// 		extend_path(path, 2 * (*path)->max_path);
// 	while ((*path)->size >= (*path)->max_ways - 1)
// 		extend_ways(path, 2 * (*path)->max_ways);
// 	(*path)->ways[(*path)->size][0] = length;
// 	i = g_end;
// 	while (length != 0)
// 	{
// 		(*path)->ways[(*path)->size][length--] = source_vertices[i];
// 		i = g_parent[i];
// 	}
// 	//detect_common_edge(path);
// 	(*path)->size++;
// }

void	save_best_choice(t_path **best_choice, t_path *path)
{
	int i;
	int j;

	if ((*best_choice)->max_ways < path->max_ways)
		extend_ways(best_choice, path->max_ways);
	if ((*best_choice)->max_path < path->max_path)
		extend_path(best_choice, path->max_path);
	(*best_choice)->max_ways = path->max_ways;
	(*best_choice)->max_path = path->max_path;
	i = -1;
	while (++i < path->size)
	{
		j = -1;
		while (++j < path->ways[i][0] + 1)
			(*best_choice)->ways[i][j] = path->ways[i][j];
	}
	(*best_choice)->step_elems = path->step_elems;
	if ((*best_choice)->steps)
		free((*best_choice)->steps);
	(*best_choice)->steps = (int*)malloc(sizeof(int) * path->step_elems);
	i = -1;
	while (++i < path->step_elems)
		(*best_choice)->steps[i] = path->steps[i];
	(*best_choice)->final_steps = path->final_steps;
	(*best_choice)->size = path->size;
}
