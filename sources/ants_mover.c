/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_mover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:47:02 by efriesen          #+#    #+#             */
/*   Updated: 2020/03/15 19:20:07 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		**create_array_of_ants(int *steps, int size)
{
	int **rez;
	int i;
	int j;
	int	check;

	i = -1;
	rez = (int**)malloc(sizeof(int*) * size);
	while (++i < size)
		rez[i] = (int*)malloc(sizeof(int) * steps[i]);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < steps[i])
			rez[i][j] = -1;
	}
	check = size - 1;
	return (crutch_create_array(check, steps, rez));
}

void	crutch_for_path_in_one_edge(char **names)
{
	int i;

	i = 0;
	while (++i <= g_ants)
		ft_printf("L%d-%s ", i, names[g_end]);
	ft_printf("\n");
}

void	print_used_paths(t_path *best, char **names)
{
	int i;
	int j;

	ft_printf("\n used paths: %d\n\n", best->size);
	i = -1;
	while (++i < best->size)
	{
		ft_printf("[%d] : %s-", best->ways[i][0], names[g_start]);
		j = 0;
		while (++j <= best->ways[i][0])
		{
			ft_printf("%s", names[best->ways[i][j]]);
			if (j != best->ways[i][0])
				ft_printf("-");
		}
		ft_printf("\n");
	}
}

void	print_paths(t_path *paths, t_path *best, char **names)
{
	int i;
	int j;

	ft_printf("-xxx: printing found paths\n\n");
	ft_printf(" found node-disjoints paths: %d\n\n", paths->size);
	i = -1;
	while (++i < paths->size)
	{
		ft_printf("[%d] : %s-", paths->ways[i][0], names[g_start]);
		j = 0;
		while (++j <= paths->ways[i][0])
		{
			ft_printf("%s", names[paths->ways[i][j]]);
			if (j != paths->ways[i][0])
				ft_printf("-");
		}
		ft_printf("\n");
	}
	print_used_paths(best, names);
}

void	ants_mover(t_path *paths, char **names, char *graph_output)
{
	int **ants;
	int current_step;
	int i;
	int j;

	ft_printf("%s\n\n", graph_output);
	if (paths->final_steps == 1)
		return (crutch_for_path_in_one_edge(names));
	ants = create_array_of_ants(paths->steps, paths->step_elems);
	current_step = 0;
	while (++current_step <= paths->final_steps)
	{
		i = -1;
		while (++i < current_step)
		{
			j = -1;
			while (++j < paths->step_elems && i < paths->steps[j])
				if (current_step - i <= paths->ways[j][0])
					ft_printf("L%d-%s ", ants[j][i],
							names[paths->ways[j][current_step - i]]);
		}
		ft_printf("\n");
	}
	clear_int_array(ants, paths->step_elems);
}
