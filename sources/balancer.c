/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balancer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:39:27 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/12 21:18:35 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*ways_steps(t_path *path)
{
	int *rez;
	int i;

	i = -1;
	rez = (int*)malloc(sizeof(int) * path->step_elems);
	while (++i < path->step_elems)
		rez[i] = path->steps[i] + path->ways[i][0] - 1;
	return (rez);
}

int		*norm_balanc(int *mas, int size)
{
	int i;
	int temp;

	i = -1;
	temp = 0;
	while (++i < size)
		temp += mas[i];
	temp = g_ants - temp;
	while (--temp > -1)
		mas[temp]++;
	return (mas);
}

int		count_avg(int *rez, int size)
{
	int avg;
	int i;

	avg = 0;
	i = -1;
	while (++i < size)
		avg += rez[i];
	avg /= i;
	return (avg);
}

int		*min_gap(int *mas, int *rez, int size)
{
	int avg;
	int i;
	int temp;

	avg = count_avg(rez, size);
	i = -1;
	while (++i < size)
	{
		if (rez[i] > avg)
		{
			temp = rez[i] - avg;
			rez[i] -= temp;
			mas[i] -= temp;
		}
		if (rez[i] < avg)
		{
			temp = avg - rez[i];
			rez[i] += temp;
			mas[i] += temp;
		}
	}
	return (norm_balanc(mas, size));
}

void balancer(t_path *path)
{
	int *rez;

	rez = ways_steps(path);
	path->steps = min_gap(path->steps, rez, path->step_elems);
	free(rez);
}
