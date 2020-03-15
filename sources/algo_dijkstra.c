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
	g_parent[g_start] = -1;
	i = -1;
	while (++i < size)
		g_dest[i] = g_infinity;
	g_dest[g_start] = 0;
}

int		get_min_dest_vertice(int size_matrix)
{
	int min_dest_vertice;
	int j;

	min_dest_vertice = -1;
	j = -1;
	while (++j < size_matrix)
		if ((g_visit[j] == 0) &&
			(min_dest_vertice == -1 || g_dest[j] < g_dest[min_dest_vertice]))
			min_dest_vertice = j;
	if (g_dest[min_dest_vertice] == g_infinity)
		return (-1);
	else
		return (min_dest_vertice);
}

void algo_dijkstra(int **links, int **matrix,
		int size_matrix, int *source_vertices)
{
	int	min_dest_vertice;
	int	i;
	int	j;

	g_arrays_preparation(size_matrix);
	i = -1;
	while (++i < size_matrix)
	{
		if ((min_dest_vertice = get_min_dest_vertice(size_matrix)) == -1)
			return ;
		g_visit[min_dest_vertice] = 1;
		j = 0;
		while (++j <= links[min_dest_vertice][0])
		{
			if (g_dest[min_dest_vertice] + matrix[min_dest_vertice]
			[links[min_dest_vertice][j]] < g_dest[links[min_dest_vertice][j]])
			{
				g_dest[links[min_dest_vertice][j]] = g_dest[min_dest_vertice] +
					matrix[min_dest_vertice][links[min_dest_vertice][j]];
				g_parent[links[min_dest_vertice][j]] = min_dest_vertice;
			}
		}
	}
}
