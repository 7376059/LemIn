/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:34:01 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/18 03:17:13 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrejoin(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*temp;

	if (!(s1) || !(s2))
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(temp = (char*)malloc(sizeof(*temp) * (len1 + len2) + 1)))
		return (0);
	len1 = -1;
	i = 0;
	while (s1[++len1])
		temp[i++] = s1[len1];
	len1 = -1;
	while (s2[++len1])
		temp[i++] = s2[len1];
	temp[i] = 0;
	free(s1);
	return (temp);
}
