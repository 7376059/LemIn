/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:27:51 by dgrady            #+#    #+#             */
/*   Updated: 2020/01/19 17:06:14 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"




int main(void)
{	
	g_start = -1;
	g_end = -1;
	t_graph *gr = init_graph();
	gr = start_parser(gr);

	print_names(gr);
	print_edges(gr);
	
	printf("\nstart_room  = %d  end_room = %d\n", g_start, g_end);

	printf("Finito La Comedia\n");
			
	return (0);
}












