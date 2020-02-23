/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:58:59 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/17 22:49:22 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		u;

	str = (char*)s;
	if (!str)
		return (NULL);
	u = -1;
	while (str[++u])
		if (str[u] == (char)c)
			return (&str[u]);
	if (str[u] == (char)c)
		return (&str[u]);
	return (NULL);
}
