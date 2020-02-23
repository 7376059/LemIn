/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_mover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:47:02 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/23 19:33:07 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int **create_array_of_ants(int *steps, int size)
{
	int **rez;
	int i;
	int j;
	int ants;

	i = -1;
	rez = (int**)malloc(sizeof(int*) * size);
	while(++i < size)
		rez[i] = (int*)malloc(sizeof(int) * steps[i]);
	i = 0;
	ants = 1;
	int check = size;

	while(ants <= g_ants)
	{
		j = -1;
		while(++j < check)
		{
			rez[j][i] = ants;
			ants++;
			if(ants > g_ants)
				break;
		}
		i++;
		if (check > 1)
			if (i >= steps[check - 1])
				check--;
	}
	return (rez);

}

void	clear_int_array(int **arr, int size_ways)
{
	int i;

	i = -1;
	while (++i < size_ways)
		free(arr[i]);
	free(arr);
}

void    ants_mover(t_path *paths, char **names)
{
	int **ants;
	int current_step;
	int i;
	int j;

	ants = create_array_of_ants(paths->steps, paths->step_elems);

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
	clear_int_array(ants, paths->size);
}
