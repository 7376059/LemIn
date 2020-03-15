/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:00:38 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/15 19:03:57 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	invalid_graph(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void	clear_mas(char **mas)
{
	int i;

	i = -1;
	while (mas[++i])
		free(mas[i]);
	free(mas);
}

void	clear_edge(t_edge *edge)
{
	t_edge *fast;
	t_edge *slow;

	if (!(edge))
		return ;
	fast = edge->next;
	slow = edge;
	while (fast)
	{
		free(slow);
		slow = fast;
		fast = fast->next;
	}
	free(slow);
}

void	clear_graph_list(t_list_graph *gr)
{
	int			i;
	t_vertex	*fast;
	t_vertex	*slow;

	i = -1;
	if (!(gr) || !(gr->vertex))
		return ;
	while (++i < gr->vector->elems)
		free(gr->vector->names[i]);
	free(gr->vector->names);
	free(gr->vector);
	fast = gr->vertex->next;
	slow = gr->vertex;
	while (fast)
	{
		clear_edge(slow->edges);
		free(slow);
		slow = fast;
		fast = fast->next;
	}
	clear_edge(slow->edges);
	free(slow);
	free(gr->graph_output);
	free(gr);
}

int		get_number(t_list_graph *gr, char *name)
{
	int i;

	i = -1;
	while (++i < gr->vector->elems)
		if (ft_strcmp(name, gr->vector->names[i]) == 0)
			return (i);
	return (-1);
}
