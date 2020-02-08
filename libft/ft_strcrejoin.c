/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcrejoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:05:01 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/18 03:16:28 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcrejoin(char *s1, char s2)
{
	size_t	len1;
	size_t	i;
	char	*temp;

	if (!(s1) || !(s2))
		return (0);
	len1 = ft_strlen(s1);
	i = -1;
	if (!(temp = (char*)malloc(sizeof(char) * (len1 + 2))))
		return (0);
	while (s1[++i])
		temp[i] = s1[i];
	temp[i] = s2;
	temp[i + 1] = 0;
	free(s1);
	return (temp);
}
