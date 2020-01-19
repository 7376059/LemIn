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


void print_matrix(char **str)
{
	int i;
	int j;

	i = 0;
	while (i < g_rooms)
	{
		j = 0;
		while (j < g_rooms)
		{
			if (str[j] == 0)
				printf("0");
			if (str[j] == 1)
				printf("1");
			if (str[j] == 2)
				printf("2");
			j++;
		}
		i++;
	}
}



char **init_matrix()
{
	char **matrix;
	int i;
	int j;

	i = 0;
	matrix = (char**)malloc(sizeof(char*) * 100);
	while(i < 100)
	{
		j = 0;
		matrix[i] = (char*)malloc(sizeof(char) * 100);
		while(j < 100)
		{
			matrix[i][j] = 0;		 
			j++;
		}
		i++;
	}
	return (matrix);
}

char **init_names()
{
	char **names;

	names = (char**)malloc(sizeof(char*) * 100);
	return (names);
	
}


t_graph *init_graph()
{
	t_graph *rez;

	rez = (t_graph*)malloc(sizeof(t_graph));
	rez->names = init_names();
	rez->matrix = init_matrix();
	g_size = 100;
	g_rooms = 0;
	return (rez);
}



int main(void)
{
 	int fd = open("./map", O_RDONLY);	
	char *line;

	t_graph *gr = init_graph();

	while ((get_next_line(fd, &line) == 1))
	{
				
	}

	return (0);
}
