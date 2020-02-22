/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:27:51 by dgrady            #+#    #+#             */
/*   Updated: 2020/02/22 19:45:45 by efriesen         ###   ########.fr       */
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
	
	algo_suurbale(gr);

    //t_path *kek = init_path();
    //kek = counter(kek);
   // printf("Ants %d\n Steps %d\n", g_ants, kek->final_steps);
   // printf("__________________\nFinal Steps %d", kek->final_steps);
    //printf("ants = %d, elenms = %d\n steps = %d\n", kek->steps[0], kek->step_elems, kek->final_steps);

	//moover(kek, gr->vector->names);
    return (0);
}
