/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:27:51 by dgrady            #+#    #+#             */
/*   Updated: 2020/02/06 18:48:52 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// lem_in exec

int main(void)
{
	g_start = -1;
	g_end = -1;
    
	t_graph *gr = init_graph();
	gr = start_parser(gr);

	//algo_suurbale(gr);

    t_path *kek = init_path();
    kek = counter(kek);
    printf("Ants %d\n Steps %d\n", g_ants, kek->final_steps);
	return (0);
}
