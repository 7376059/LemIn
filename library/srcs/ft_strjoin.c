/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 00:42:04 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/15 21:39:37 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count_concat;
	size_t	count_s;
	char	*str_concat;

	if (!s1 || !s2)
		return (NULL);
	if (!(str_concat = (char*)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2)) + sizeof(char))))
		return (NULL);
	str_concat[ft_strlen(s1) + ft_strlen(s2)] = 0;
	count_concat = 0;
	count_s = 0;
	while (s1[count_s])
		str_concat[count_concat++] = s1[count_s++];
	count_s = 0;
	while (s2[count_s])
		str_concat[count_concat++] = s2[count_s++];
	return (str_concat);
}
