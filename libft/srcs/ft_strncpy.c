/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:48:24 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/18 17:55:28 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t u;

	u = 0;
	while (src[u] && u < len)
	{
		dst[u] = src[u];
		u++;
	}
	dst[u] = '\0';
	while (u < len)
		dst[u++] = '\0';
	return (dst);
}
