/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:11:35 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*temp;
	size_t	i;
	size_t	j;

	if (!(s))
		return (0);
	if (!(temp = (char*)malloc(sizeof(*temp) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	while (s[i])
	{
		temp[j] = s[i];
		i++;
		j++;
	}
	temp[j--] = 0;
	while (temp[j] == '\n' || temp[j] == '\t' || temp[j] == ' ')
	{
		temp[j] = 0;
		j--;
	}
	return (temp);
}
