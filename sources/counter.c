/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:50:06 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/12 21:34:27 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*steps_creator(int count, int *size, int flag)
{
	static	int	*rez;
	int			i;

	if (flag == 1)
		rez = NULL;
	if (rez == NULL && flag == 0)
	{
		rez = (int*)malloc(sizeof(int) * count);
		*size = count;
		i = -1;
		while (++i < count)
			rez[i] = 0;
	}
	if (flag == 0)
	{
		i = -1;
		while (++i < count)
			rez[i]++;
	}
	return (rez);
}

int		set_koef(void)
{
	if (g_ants < 100)
		return (1);
	if (g_ants < 500)
		return (2);
	if (g_ants < 1000)
		return (4);
	if (g_ants < 40000)
		return (8);
	if (g_ants < 80000)
		return (7);
	if (g_ants < 160000)
		return (8);
	return (9);
}

void counter(t_path *path)
{
	if(path->steps)
		free(path->steps);
	if (path->size > 1)
		return (counter2(path));
	path->steps = (int*)malloc(sizeof(int) * 1);
	path->steps[0] = g_ants;
	path->step_elems = 1;
	path->final_steps = g_ants + path->ways[0][0] - 1;
	//if (path->step_elems == 1 && path->ways[0][0] == 1)
		        //path->final_steps -= 1;
}

void balanc_path(t_path *path)
{
	balancer(path);
	path->final_steps = path->steps[0] + path->ways[0][0] - 1;
	steps_creator(0, 0, 1);
	if (path->step_elems == 1 && path->ways[0][0] == 1)
		path->final_steps -= 1;
}

void counter2(t_path *path)
{
	int ants;
	int first;
	int count;
	int temp;
	int rez;

	ants = g_ants;
	rez = 0;
	while (ants > 0)
	{
		count = 1;
		first = ants + path->ways[0][0] - 1;
		while (first > path->ways[count][0])
		{
			temp = (first - path->ways[count][0]) / count;
			first = temp + path->ways[count][0] - 1 + (temp * set_koef());
			count++;
			if (count > path->size - 1)
				break ;
		}
		ants -= count;
		rez++;
		path->steps = steps_creator(count, &path->step_elems, 0);
	}
	return (balanc_path(path));
}
