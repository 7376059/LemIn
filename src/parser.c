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



t_graph *get_name(t_graph *gr)
{

}




t_graph *start_pracer(t_graph *gr)
{
	int fd = open("./map", O_RDONLY);
	char *line;
	int i;

	i = 0;
	while ((get_next_line(fd, &line) == 1))
	{
		if(i == 0)
			g_ants == ft_atoi(line); //   тут проврека на говно
		else if (ft_strcmp(line, "##start") == 0)
		{
			g_start = i;
			continue ;
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			g_end = i;
			continue ;
		}
		else if (line[0] == '#' && line[1] != '#' || line[0] == '#' && line[1] == '#' && ft_strcmp(line, "##start") != 0 && ft_strcmp(line, "##end") != 0)
			continue ;
		else 
		{

		}
		i++;
	}
		
	
}
