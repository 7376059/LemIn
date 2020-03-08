/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:27:51 by dgrady            #+#    #+#             */
/*   Updated: 2020/02/23 19:57:06 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lemin.h"

// lem_in exec

int main(void)
{
	g_start = -1;
	g_end = -1;

	t_list_graph *gr = init_list_graph();
	gr = start_parser(gr);

	ft_printf("\n");
	algo_suurbale(gr);

	clear_graph_list(gr);
    return (0);
}
