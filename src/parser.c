/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:01:51 by dgrady            #+#    #+#             */
/*   Updated: 2020/01/19 17:56:22 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

int validate_name(char **name)
{
	int i;
	
	i = -1;
	if (name[0][0] == 'L')
		return (0);
	while(name[1][++i])
		if (!ft_isdigit(name[1][i]))
			return (0);
	i = -1;
	while(name[2][++i])
        if (!ft_isdigit(name[2][i]))
            return (0);
	return (1);
}

int get_number(t_graph *gr, char *name)
{
	int i;

	i = -1;
	while (++i < gr->vector->elems)
		if(ft_strcmp(name, gr->vector->names[i]) == 0)
			return (i);
	return (-1);
}


int validate_edge(t_graph *gr, char **name)
{
	int	i;
	int flag;	

	i = -1;
	flag = 0;
	while(++i < gr->vector->elems)
		if(ft_strcmp(name[0], gr->vector->names[i]) == 0)
			flag++;
	i = -1;
	while(++i < gr->vector->elems)
        if(ft_strcmp(name[1], gr->vector->names[i]) == 0)
            flag++;
	if (flag == 2)
		return (1);
	printf("flag = %d\n", flag);
	printf ("%s   %s\n", name[0], name[1]);
	return (0);
}


t_graph *get_name(t_graph *gr, char **line)
{
	if (!(validate_name(line)))
		throw_error(gr);
	gr->vector = vector_push(gr->vector, line[0]);
	return (gr);
}

t_graph *get_edge(t_graph *gr, char **line)
{
	if (!validate_edge(gr, line))
		throw_error(gr);
	if (g_start == -1 || g_end == -1)
		throw_error(gr);
	if(gr->edges == NULL)
		gr->edges = init_edge(get_number(gr, line[0]), get_number(gr, line[1]));
	else
		gr->edges = add_edge(gr->edges, get_number(gr, line[0]), get_number(gr, line[1]));
	return (gr);
}



t_graph *start_parser(t_graph *gr)
{
	char *line;
	int flag;
	char **split;
	char a;

	get_next_line(0, &line);
	g_ants = ft_atoi(line);

	flag = 0;

	while ((get_next_line(0, &line) == 1))
	{
		if (ft_strcmp(line, "##start") == 0)
			g_start = gr->vector->elems;
		else if (ft_strcmp(line, "##end") == 0)
			g_end = gr->vector->elems;
		else if (line[0] == '#')
			continue ;
		else 
		{
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
		}
	}
	return (gr);
}
