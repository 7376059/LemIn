/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:57:31 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/16 18:28:56 by efriesen         ###   ########.fr       */
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

int		get_first(int ants, int way)
{
	int first;

	first = ants + way - 1;
	if (first < 0)
		invalid_graph();
	return (first);
}

int		**crutch_create_array(int size, int *steps, int **rez)
{
	int i;
	int j;
	int ants;

	i = 0;
	ants = 1;
	while (ants <= g_ants && (j = -1))
	{
		while (++j <= size)
		{
			rez[j][i] = ants;
			ants++;
			if (ants > g_ants)
				break ;
		}
		i++;
		while (steps[size] == i)
		{
			if (size == 0)
				break ;
			size--;
		}
	}
	return (rez);
}

char	*ft_strjoin_slash_n(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + sizeof(char) * 2);
	j = 0;
	if (s1)
	{
		i = 0;
		while (s1[i])
			str[j++] = s1[i++];
		str[j++] = '\n';
		free(s1);
	}
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
