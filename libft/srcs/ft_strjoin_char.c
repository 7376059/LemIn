/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:33:14 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/15 23:04:03 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *str, char c)
{
	char	*new_str;
	size_t	i;

	if (!(new_str = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	i = 0;
	if (str)
		while (i < ft_strlen(str))
		{
			new_str[i] = str[i];
			i++;
		}
	new_str[i] = c;
	new_str[++i] = '\0';
	return (new_str);
}
