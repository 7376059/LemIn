/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:30:46 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
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
