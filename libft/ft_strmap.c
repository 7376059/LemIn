/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:29:30 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	temp = (char*)malloc(sizeof(*temp) * ft_strlen(s) + 1);
	if (!temp)
		return (NULL);
	while (s[++i])
		temp[i] = f(s[i]);
	temp[i] = 0;
	return (temp);
}
