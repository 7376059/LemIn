/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:01:51 by dgrady            #+#    #+#             */
/*   Updated: 2020/02/23 18:04:00 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph	*get_name(t_graph *gr, char **line)
{
	static int i = -1;

	i++;
	if (!(validate_name(line)))
		throw_error(gr);
	if (gr->vertex == NULL)
		gr->vertex = init_vertex(i);
	else
		gr->vertex = add_vertex(gr->vertex, i);
	gr->vector = vector_push(gr->vector, line[0]);
	return (gr);
}

int		validate_edge(t_graph *gr, char **name)
{
	int	i;
	int flag;

	i = -1;
	flag = 0;
	while (++i < gr->vector->elems)
		if (ft_strcmp(name[0], gr->vector->names[i]) == 0)
			flag++;
	i = -1;
	while (++i < gr->vector->elems)
		if (ft_strcmp(name[1], gr->vector->names[i]) == 0)
			flag++;
	if (flag == 2)
		return (1);
	return (0);
}

t_graph	*get_edge(t_graph *gr, char **line)
{
	int			first;
	int			second;
	int			i;
	int			j;
	t_vertex	*temp;

	temp = gr->vertex;
	if (!validate_edge(gr, line))
		throw_error(gr);
	if (g_start == -1 || g_end == -1)
		throw_error(gr);
	first = get_number(gr, line[0]);
	second = get_number(gr, line[1]);
	i = 0;
	while (i++ < first)
		temp = temp->next;
	temp->edges = add_edge(temp->edges, second);
	temp = gr->vertex;
	i = 0;
	while (i++ < second)
		temp = temp->next;
	temp->edges = add_edge(temp->edges, first);
	return (gr);
}

t_graph	*norm_parcer(t_graph *gr, char *line)
{
	char		**split;
	static int	flag = 0;

	split = ft_strsplit(line, ' ');
	if (flag == 0 && get_mas_length(split) == 3)
		gr = get_name(gr, split);
	else if (get_mas_length(split) == 1)
	{
		flag = 1;
		clear_mas(split);
		split = ft_strsplit(line, '-');
		gr = get_edge(gr, split);
	}
	else
		throw_error(gr);
	clear_mas(split);
	return (gr);
}

t_graph	*start_parser(t_graph *gr)
{
	char	*line;
	char	a;

	if (!(get_next_line(0, &line)))
			throw_error(gr);
	g_ants = get_ants(line, gr);
	free(line);
	while ((get_next_line(0, &line) == 1))
	{
		if (ft_strcmp(line, "##start") == 0)
			g_start = gr->vector->elems;
		else if (ft_strcmp(line, "##end") == 0)
			g_end = gr->vector->elems;
		else if (line[0] == '#')
			;
		else
			gr = norm_parcer(gr, line);
		free(line);
	}
	return (gr);
}
