/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_vertex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:08:25 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/15 19:09:55 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_vertex	*init_vertex(int number)
{
	t_vertex *rez;

	rez = (t_vertex*)malloc(sizeof(t_vertex));
	rez->room = number;
	rez->next = NULL;
	rez->edges = NULL;
	return (rez);
}

t_vertex	*add_vertex(t_vertex *start, int number)
{
	t_vertex *temp;

	temp = start;
	while (temp->next)
		temp = temp->next;
	temp->next = init_vertex(number);
	return (start);
}

t_edge		*init_edge(int a)
{
	t_edge *rez;

	rez = (t_edge*)malloc(sizeof(t_edge));
	rez->cost = 1;
	rez->to = a;
	rez->next = NULL;
	return (rez);
}

t_edge		*add_edge(t_edge *start, int a)
{
	t_edge *temp;
	t_edge *new;

	if (start == NULL)
		return (init_edge(a));
	temp = start;
	new = init_edge(a);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (start);
}
