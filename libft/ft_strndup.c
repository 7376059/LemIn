/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:44:39 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 20:44:39 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	temp = (char*)malloc(sizeof(*temp) * (i + 1));
	if (!(temp))
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
