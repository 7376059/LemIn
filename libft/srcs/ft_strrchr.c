/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:21:52 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/17 23:05:56 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		last;
	int		u;

	str = (char*)s;
	u = -1;
	last = -1;
	while (str[++u])
		if ((unsigned char)str[u] == (unsigned char)c)
			last = u;
	if ((unsigned char)str[u] == (unsigned char)c)
		return (&str[u]);
	if (last != -1)
		return (&str[last]);
	return (NULL);
}
