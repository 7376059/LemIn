/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:00:33 by efriesen          #+#    #+#             */
/*   Updated: 2020/03/15 18:47:05 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_path(t_path **paths)
{
	t_path	*path;
	int		i;

	*paths = (t_path*)malloc(sizeof(t_path));
	path = (*paths);
	path->max_ways = 100;
	path->max_path = 100;
	path->size = 0;
	path->final_steps = 0;
	path->step_elems = 0;
	path->steps = NULL;
	path->ways = (int**)malloc(sizeof(int*) * path->max_ways);
	i = -1;
	while (++i < path->max_ways)
		path->ways[i] = (int*)malloc(sizeof(int) * path->max_path);
}

void	re_binding_paths(t_path *path, int crossing_path,
	int pos_in_crossing_path, int pos_in_added_path)
{
	int len_re_bind;
	int i;

	len_re_bind = 0;
	while (path->ways[path->size][pos_in_added_path + len_re_bind + 1] ==
			path->ways[crossing_path][pos_in_crossing_path - len_re_bind - 1])
		len_re_bind++;
	i = -1;
	while ((++i + pos_in_added_path + len_re_bind) <= path->ways[path->size][0])
		path->ways[path->size + 1][i + 1] =
			path->ways[path->size][i + pos_in_added_path + len_re_bind];
	path->ways[path->size + 1][0] = i;
	i = 0;
	while (++i + pos_in_crossing_path <= path->ways[crossing_path][0])
		path->ways[path->size][pos_in_added_path + i] =
			path->ways[crossing_path][pos_in_crossing_path + i];
	path->ways[path->size][0] = pos_in_added_path + --i;
	i = -1;
	while (++i < path->ways[path->size + 1][0])
		path->ways[crossing_path][pos_in_crossing_path - len_re_bind + i] =
			path->ways[path->size + 1][i + 1];
	path->ways[crossing_path][0] = pos_in_crossing_path - len_re_bind + --i;
}

void	detect_crossing_paths(t_path *path)
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
				if (path->ways[path->size][position_in_added_path] ==
						path->ways[current_path][position_in_current_path]
					&& path->ways[path->size][position_in_added_path + 1] ==
						path->ways[current_path][position_in_current_path - 1])
					return (re_binding_paths(path, current_path,
						position_in_current_path, position_in_added_path));
		}
	}
}

void	swap_paths(t_path *paths, int p1, int p2)
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

void	sort_paths(t_path *paths)
{
	int position_max_length_path;
	int min;
	int max_length_path;
	int i;
	int j;

	i = -1;
	while (++i < paths->size)
	{
		min = paths->ways[0][0];
		max_length_path = 0;
		j = -1;
		while (++j < paths->size - i)
		{
			min = (min > paths->ways[j][0]) ? paths->ways[j][0] : min;
			if (paths->ways[j][0] > max_length_path)
			{
				max_length_path = paths->ways[j][0];
				position_max_length_path = j;
			}
		}
		if (max_length_path <= min)
			return ;
		swap_paths(paths, position_max_length_path, paths->size - i - 1);
	}
}
