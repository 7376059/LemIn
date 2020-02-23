/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:21:40 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/14 23:19:09 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		u;
	char	*str;

	u = 0;
	while (src[u])
		u++;
	if (!(str = (char*)malloc(sizeof(char) * u + 1)))
		return (NULL);
	str[u] = '\0';
	while (u--)
		str[u] = src[u];
	return (str);
}
