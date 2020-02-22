/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:56:40 by efriesen          #+#    #+#             */
/*   Updated: 2018/11/27 19:14:44 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	u;

	u = 0;
	while (s1[u] || s2[u])
	{
		if (s1[u] != s2[u])
			return ((unsigned char)s1[u] - (unsigned char)s2[u]);
		u++;
	}
	return (0);
}
