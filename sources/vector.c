/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:04:32 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/15 19:05:44 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_vector	*init_vector(void)
{
	t_vector *rez;

	rez = (t_vector*)malloc(sizeof(t_vector));
	rez->size = 1000;
	rez->elems = 0;
	rez->names = (char**)malloc(sizeof(char*) * rez->size);
	return (rez);
}

t_vector	*realloc_vector(t_vector *temp, char *line)
{
	t_vector	*new;
	int			i;

	i = -1;
	new = (t_vector*)malloc(sizeof(t_vector));
	new->names = (char**)malloc(sizeof(char*) * temp->size * 2);
	new->size = temp->size * 2;
	new->elems = temp->elems;
	while (++i < temp->elems)
		new->names[i] = temp->names[i];
	new = vector_push(new, line);
	free(temp->names);
	free(temp);
	return (new);
}

t_vector	*vector_push(t_vector *temp, char *line)
{
	if (temp->elems < temp->size)
	{
		temp->names[temp->elems] = ft_strdup(line);
		temp->elems++;
	}
	else
		temp = realloc_vector(temp, line);
	return (temp);
}
