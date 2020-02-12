/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:12:13 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;
	size_t	i;

	if (size == (size_t)-1)
		return (NULL);
	temp = (char*)malloc(sizeof(*temp) * (size + 1));
	if (!(temp))
		return (NULL);
	temp[size] = 0;
	i = 0;
	while (i < size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
