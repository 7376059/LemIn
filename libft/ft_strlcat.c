/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:34:03 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	if (ft_strlen(src) >= (size - i - 1))
	{
		ft_memcpy(dst + i, src, size - i - 1);
		dst[size - 1] = 0;
	}
	else
		ft_memcpy(dst + i, src, ft_strlen(src) + 1);
	return (i + ft_strlen(src));
}
