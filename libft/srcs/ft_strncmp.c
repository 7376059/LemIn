/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:06:40 by efriesen          #+#    #+#             */
/*   Updated: 2018/11/27 19:16:33 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	t;
	int		u;

	t = 0;
	u = 0;
	while ((s1[u] || s2[u]) && t < n)
	{
		if (s1[u] != s2[u])
			return ((unsigned char)s1[u] - (unsigned char)s2[u]);
		u++;
		t++;
	}
	return (0);
}
