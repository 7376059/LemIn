/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:59:44 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/15 19:03:34 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list_graph	*init_list_graph(void)
{
	t_list_graph *rez;

	rez = (t_list_graph*)malloc(sizeof(t_list_graph));
	rez->vector = init_vector();
	rez->vertex = NULL;
	rez->graph_output = NULL;
	return (rez);
}

int				get_mas_length(char **mas)
{
	int i;

	i = -1;
	while (mas[++i])
		;
	return (i);
}

void			throw_error(t_list_graph *gr)
{
	write(1, "ERROR\n", 6);
	clear_graph_list(gr);
	exit(0);
}

int				get_ants(char *line, t_list_graph *gr)
{
	int i;
	int rez;

	i = -1;
	if (ft_strlen(line) == 0)
		throw_error(gr);
	while (line[++i])
		if (ft_isdigit(line[i]) == 0)
			throw_error(gr);
	rez = ft_atoi(line);
	if (rez <= 0)
		throw_error(gr);
	return (rez);
}

int				validate_name(char **name)
{
	int i;

	i = -1;
	if (name[0][0] == 'L')
		return (0);
	while (name[1][++i])
		if (!ft_isdigit(name[1][i]))
			return (0);
	i = -1;
	while (name[2][++i])
		if (!ft_isdigit(name[2][i]))
			return (0);
	return (1);
}
