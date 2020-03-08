/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:00:33 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/17 17:12:19 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_path(t_path **paths)
{
	t_path	*path;
	int		i;

	*paths = (t_path*)malloc(sizeof(t_path));
	path = (*paths);
	path->max_ways = 10; // еще раз проверить память
	path->max_path = 10;
	path->size = 0;
	path->final_steps = 0;
	path->step_elems = 0;
	path->steps = NULL;
	path->ways = (int**)malloc(sizeof(int*) * path->max_ways);
	i = -1;
	while (++i < path->max_ways)
		path->ways[i] = (int*)malloc(sizeof(int) * path->max_path);
}

// void	modific_ways(t_path **path, int i, int j, int k)
// {
// 	int u;
//
// 	u = 0;
// 	while (i + ++u < (*path)->ways[(*path)->size][0] + 1)
// 		(*path)->ways[(*path)->size + 1][u] = (*path)->ways[(*path)->size][i + u];
// 	(*path)->ways[(*path)->size + 1][0] = u - 1;
//
// 	for (int j = 0; j < (*path)->size + 2; j++)
// 	{
// 		printf("[%d] ", (*path)->ways[j][0]);
// 		for (int k = 1; k <= (*path)->ways[j][0]; k++)
// 			printf("%d ", (*path)->ways[j][k]);
// 		printf("\n");
// 	}
// 	printf("\n");
//
// 	u = -1;
// 	while (k + ++u < (*path)->ways[j][0] + 1)
// 		(*path)->ways[(*path)->size][i + u] = (*path)->ways[j][k + u];
// 	(*path)->ways[(*path)->size][0] = i + u - 1;
// 	u = -1;
// 	while (++u < (*path)->ways[(*path)->size + 1][0] + 1)
// 		(*path)->ways[j][k + u - 1] = (*path)->ways[(*path)->size + 1][u + 1];
// 	(*path)->ways[j][0] = u + k - 3;
// }

void re_binding_paths(t_path *path, int crossing_path,
	int position_in_crossing_path, int position_in_added_path)
{
	int length_re_binding;
	int i;

	length_re_binding = 0;
	while (path->ways[path->size][position_in_added_path + length_re_binding + 1]
		== path->ways[crossing_path][position_in_crossing_path  - length_re_binding - 1])
		length_re_binding++;

	//printf("length_re_binding [%d]\n", length_re_binding);

	// printf("\nposition_in_crossing_path %d\n", position_in_crossing_path);
	// printf("position_in_added_path %d\n", position_in_added_path);
	// printf("length_re_binding %d\n\n", length_re_binding);

	// for (int j = 0; j < path->size + 2; j++)
	// {
	// 	printf("[%d] ", path->ways[j][0]);
	// 	for (int k = 1; k <= path->ways[j][0]; k++)
	// 		printf("%d ", path->ways[j][k]);
	// 	printf("\n");
	// }
	// printf("\n");

	i = -1;
	while ((++i + position_in_added_path + length_re_binding) <= path->ways[path->size][0])
		path->ways[path->size + 1][i + 1] = path->ways[path->size][i + position_in_added_path + length_re_binding];
	path->ways[path->size + 1][0] = i;

	i = 0;
	while (++i + position_in_crossing_path <= path->ways[crossing_path][0])
		path->ways[path->size][position_in_added_path + i] = path->ways[crossing_path][position_in_crossing_path + i];
	path->ways[path->size][0] = position_in_added_path + --i;

	i = -1;
	while (++i < path->ways[path->size + 1][0])
		path->ways[crossing_path][position_in_crossing_path - length_re_binding + i] = path->ways[path->size + 1][i + 1];
	path->ways[crossing_path][0] = position_in_crossing_path - length_re_binding + --i;

	// for (int j = 0; j < path->size + 2; j++)
	// {
	// 	printf("[%d] ", path->ways[j][0]);
	// 	for (int k = 1; k <= path->ways[j][0]; k++)
	// 		printf("%d ", path->ways[j][k]);
	// 	printf("\n");
	// }
	// printf("\n");
}

void detect_crossing_paths(t_path *path) // попробовать ускорить заменой переменной
{
	int position_in_added_path;
	int position_in_current_path;
	int current_path;

	position_in_added_path = 1;
	while (++position_in_added_path < path->ways[path->size][0] - 1)
	{
		current_path = -1;
		while (++current_path < path->size)
		{
			position_in_current_path = 1;
			while (++position_in_current_path < path->ways[current_path][0])
				if (path->ways[path->size][position_in_added_path] == path->ways[current_path][position_in_current_path]
					&& path->ways[path->size][position_in_added_path + 1] == path->ways[current_path][position_in_current_path - 1])
					return (re_binding_paths(path, current_path, position_in_current_path, position_in_added_path));
		}
	}
}

// void	detect_common_edge(t_path **path) // затестить скорость заменив разыменование
// {
// 	int i;
// 	int j;
// 	int k;
//
// 	i = 0;
// 	while (++i < (*path)->ways[(*path)->size][0] - 1)
// 	{
// 		j = -1;
// 		while (++j < (*path)->size)
// 		{
// 			k = 1;
// 			while (++k < (*path)->ways[j][0])
// 			{
// 				if (((*path)->ways[(*path)->size][i] == (*path)->ways[j][k])
// 						&& ((*path)->ways[(*path)->size][i + 1]	== (*path)->ways[j][k - 1]))
// 					return (modific_ways(path, i + 1, j, k + 1));
// 			}
// 		}
// 	}
// }

// void	swap_paths(t_path **path, int a, int b)
// {
// 	int i;
//
// 	i = -1;
// 	while (++i < (*path)->ways[a][0] + 1)
// 		(*path)->ways[(*path)->size][i] = (*path)->ways[a][i];
// 	i = -1;
// 	while (++i < (*path)->ways[b][0] + 1)
// 		(*path)->ways[a][i] = (*path)->ways[b][i];
// 	i = -1;
// 	while (++i < (*path)->ways[(*path)->size][0] + 1)
// 		(*path)->ways[b][i] = (*path)->ways[(*path)->size][i];
// }

void swap_paths(t_path *paths, int p1, int p2)
{
	int i;

	i = -1;
	while (++i <= paths->ways[p1][0])
		paths->ways[paths->size][i] = paths->ways[p1][i];
	i = -1;
	while (++i <= paths->ways[p2][0])
		paths->ways[p1][i] = paths->ways[p2][i];
	i = -1;
	while (++i <= paths->ways[paths->size][0])
		paths->ways[p2][i] = paths->ways[paths->size][i];
}

void sort_paths(t_path *paths)
{
	int position_max_length_path;
	int min_length_path;
	int max_length_path;
	int i;
	int j;

	i = -1;
	while (++i < paths->size)
	{
		min_length_path = paths->ways[0][0];
		max_length_path = 0;
		j = -1;
		while (++j < paths->size - i)
		{
			if (min_length_path > paths->ways[j][0])
				min_length_path = paths->ways[j][0];
			if (paths->ways[j][0] > max_length_path)
			{
				max_length_path = paths->ways[j][0];
				position_max_length_path = j;
			}
		}
		if (max_length_path > min_length_path)
			swap_paths(paths, position_max_length_path, paths->size - i - 1);
		else
			return ;
	}
}

// void	sort_paths(t_path *path) // лишние действия
// {
// 	int max_path;
// 	int position;
// 	int i;
// 	int j;
//
// 	if ((*path)->size == 1)
// 		return ;
// 	i = -1;
// 	while (++i < (*path)->size)
// 	{
// 		max_path = 0;
// 		position = 0;
// 		j = -1;
// 		while (++j < (*path)->size - i)
// 		{
// 			if ((*path)->ways[j][0] > max_path)
// 			{
// 				max_path = (*path)->ways[j][0];
// 				position = j;
// 			}
// 		}
// 		//if ((*path)->ways[(*path)->size - i - 1][0] == max_path)
// 		//	break ;
// 		swap_paths(path, position, (*path)->size - i - 1);
// 	}
// }
