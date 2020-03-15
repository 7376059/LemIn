/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:44:45 by efriesen          #+#    #+#             */
/*   Updated: 2020/03/14 12:44:46 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	clear_path(t_path *paths)
{
	clear_int_array(paths->ways, paths->max_ways);
	free(paths->steps);
	free(paths);
}

void clear_graph(t_graph *graph)
{
	int i;

	i = -1;
	while (++i < graph->max_size_matrix)
	{
		free(graph->adjacency_matrix[i]);
		free(graph->links_in_matrix[i]);
	}
	free(graph->adjacency_matrix);
	free(graph->links_in_matrix);
	free(graph->source_vertices);
	free(graph->duplicated_vertices);
	free(graph);
}

void	clear_int_array(int **arr, int size_ways)
{
	int i;

	i = -1;
	while (++i < size_ways)
		free(arr[i]);
	free(arr);
}
