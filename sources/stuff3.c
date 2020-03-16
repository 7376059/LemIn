/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:57:31 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/16 18:14:55 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_first(int ants, int way)
{
	int first;

	first = ants + way - 1;
	if (first < 0)
		invalid_graph();
	return (first);
}

int		**crutch_create_array(int size, int *steps, int **rez)
{
	int i;
	int j;
	int ants;
	int check;

	i = 0;
	ants = 1;
	check = size - 1;
	while (ants <= g_ants)
	{
		j = -1;
		while (++j <= check)
		{
			rez[j][i] = ants;
			ants++;
			if (ants > g_ants)
				break ;
		}
		i++;
		while (check >= 0 && steps[check] == i)
			check--;
	}
	return (rez);
}

char	*ft_strjoin_slash_n(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + sizeof(char) * 2);
	j = 0;
	if (s1)
	{
		i = 0;
		while (s1[i])
			str[j++] = s1[i++];
		str[j++] = '\n';
		free(s1);
	}
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
