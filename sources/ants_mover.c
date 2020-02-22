/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_mover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:47:02 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/22 19:33:55 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     **create_array_of_ants(int **ways, int size_ways, int *steps, int size_steps)
{
	int **ants;
	int i;
	int j;
	int k;

	ants = (int**)malloc(sizeof(int*) * size_ways);
	i = -1;
	while (++i < size_ways)
	{
		ants[i] = (int*)malloc(sizeof(int) * steps[i]);
		j = i + 1;
		k = -1;
		while (++k < steps[i])
		{
			ants[i][k] = j;
			j += 3;
		}
	}
	return (ants);
}

void    ants_mover(t_path *paths, char **names)
{
	int **ants;
	int current_step;
	int i;
	int j;

	ants = create_array_of_ants(paths->ways, paths->size, paths->steps, paths->step_elems);

	current_step = 0;
	while (++current_step <= paths->final_steps)
	{
		i = -1;
		while (++i < current_step)
		{
			j = -1;
			while (++j < paths->size && i < paths->steps[j])
				if (current_step - i <= paths->ways[j][0])
					ft_printf("L%d-%s ", ants[j][i], names[paths->ways[j][current_step - i]]);

		}
		ft_printf("\n");
	}
}
