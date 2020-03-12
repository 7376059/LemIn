/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:27:51 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/12 23:45:32 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lemin.h"

void print_usage(void)
{
	ft_printf("usage:  ./lem-in  [-xxx] < ant_farm\n");
	ft_printf("\t-xxx: for print paths\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_list_graph *list_graph;

	if ((argc == 2 && !ft_strequ(argv[1], "-xxx")) || argc > 2)
		print_usage();
	else if (argc == 1)
		g_print_paths = 0;
	else
		g_print_paths = 1;
	g_start = -1;
	g_end = -1;
	list_graph = init_list_graph();
	list_graph = start_parser(list_graph);
	g_dest = NULL;
	g_parent = NULL;
	g_visit = NULL;
	g_infinity = 1000000000;

	ft_printf("\n");

	algo_suurbale(list_graph);

	clear_graph_list(list_graph);
  return (0);
}
