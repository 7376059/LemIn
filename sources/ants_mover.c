/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_mover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:47:02 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/24 17:08:06 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int **create_array_of_ants(int *steps, int size)
{
	int **rez;
	int i;
	int j;
	int ants;
	int  check;

	i = -1;
	rez = (int**)malloc(sizeof(int*) * size);
	while(++i < size)
		rez[i] = (int*)malloc(sizeof(int) * steps[i]);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < steps[i])
			rez[i][j] = -1;
	}


	i = 0;
	ants = 1;
	check = size - 1;
	//printf("size = %d\nants = %d\n", size, g_ants);
	while(ants <= g_ants)
	{
		j = -1;
		while (++j <= check)
		{
			rez[j][i] = ants;
			ants++;
			if (ants > g_ants)
				break ;
		}
		i++;
		while (steps[check] == i)
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

	i = -1;
	//ПУТЬ|КОЛВО_МУРАВЬЕВ КОТОРОЕ ПУСКАЮ В ЭТОТ ПУТЬ| ДЛИННА ПУТИ
	printf("WAY\t| ANTS\t| SIZE\n");	
	while(++i < paths->step_elems)
		printf("[%d] \t| %d \t| %d\n", i, paths->steps[i], paths->ways[i][0]);
	// ВЫВОЖУ САМ МАССИВ
	i = -1;
	while (++i < paths->step_elems)
	{
		j = -1;
		while (++j < paths->steps[i])
		{
			printf("%d ", ants[i][j]);
		}

		printf("\n");
	}

	/*
	while(++i < paths->step_elems)
	{
		printf("%d | ", paths->steps[i]);
		j = 0;
		while (++j <= paths->ways[i][0])
		{
			printf("%s", names[paths->ways[i][j]]);
		printf(" - ");
		}
		printf("\n");
	}	
	*/
	/*
	current_step = 0;
	while (++current_step <= paths->final_steps)
	{
		i = -1;
		while (++i < current_step)
		{
			j = -1;
			while (++j < paths->step_elems && i < paths->steps[j])
				if (current_step - i <= paths->ways[j][0])
					ft_printf("L%d-%s ", ants[j][i], names[paths->ways[j][current_step - i]]);

		}
		ft_printf("\n");
	}
	*/
	clear_int_array(ants, paths->step_elems);
}
