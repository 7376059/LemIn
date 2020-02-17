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
	path->max_ways = 1;
	path->max_path = 1;
	path->size = 0;
	path->final_steps = 0;
	path->step_elems = 0;
	path->steps = NULL;
	path->ways = (int**)malloc(sizeof(int*) * path->max_ways);
	i = -1;
	while (++i < path->max_ways)
		path->ways[i] = (int*)malloc(sizeof(int) * path->max_path);
}

void	modific_ways(t_path **path, int i, int j, int k)
{
	int u;

	u = 0;
	while (i + ++u < (*path)->ways[(*path)->size][0] + 1)
		(*path)->ways[(*path)->size + 1][u] =
			(*path)->ways[(*path)->size][i + u];
	(*path)->ways[(*path)->size + 1][0] = u - 1;
	u = -1;
	while (k + ++u < (*path)->ways[j][0] + 1)
		(*path)->ways[(*path)->size][i + u] = (*path)->ways[j][k + u];
	(*path)->ways[(*path)->size][0] = i + u - 1;
	u = -1;
	while (++u < (*path)->ways[(*path)->size + 1][0] + 1)
		(*path)->ways[j][k + u - 1] = (*path)->ways[(*path)->size + 1][u + 1];
	(*path)->ways[j][0] = u + k - 3;
}

void	detect_common_edge(t_path **path)
{
	int i;
	int j;
	int k;

	i = 0;
	while (++i < (*path)->ways[(*path)->size][0] - 1)
	{
		j = -1;
		while (++j < (*path)->size)
		{
			k = 1;
			while (++k < (*path)->ways[j][0])
			{
				if (((*path)->ways[(*path)->size][i] == (*path)->ways[j][k])
						&& ((*path)->ways[(*path)->size][i + 1]
							== (*path)->ways[j][k - 1]))
					return (modific_ways(path, i + 1, j, k + 1));
			}
		}
	}
}

void	swap_paths(t_path **path, int a, int b)
{
	int i;

	i = -1;
	while (++i < (*path)->ways[a][0] + 1)
		(*path)->ways[(*path)->size][i] = (*path)->ways[a][i];
	i = -1;
	while (++i < (*path)->ways[b][0] + 1)
		(*path)->ways[a][i] = (*path)->ways[b][i];
	i = -1;
	while (++i < (*path)->ways[(*path)->size][0] + 1)
		(*path)->ways[b][i] = (*path)->ways[(*path)->size][i];
}

void	sort_paths(t_path **path)
{
	int max_path;
	int position;
	int i;
	int j;

	if ((*path)->size == 1)
		return ;
	i = -1;
	while (++i < (*path)->size)
	{
		max_path = 0;
		position = 0;
		j = -1;
		while (++j < (*path)->size - i)
		{
			if ((*path)->ways[j][0] > max_path)
			{
				max_path = (*path)->ways[j][0];
				position = j;
			}
		}
		if ((*path)->ways[(*path)->size - i - 1][0] == max_path)
			break ;
		swap_paths(path, position, (*path)->size - i - 1);
	}
}
