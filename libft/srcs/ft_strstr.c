/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:54:51 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/18 22:56:27 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str_hay;
	char	*str_ret;
	int		h_count;
	int		n_count;

	str_hay = (char*)haystack;
	if (!needle[0])
		return (str_hay);
	h_count = 0;
	while (str_hay[h_count])
	{
		n_count = 0;
		str_ret = &str_hay[h_count];
		while (needle[n_count] && needle[n_count] == str_hay[h_count + n_count])
			n_count++;
		if (!needle[n_count])
			return (str_ret);
		h_count++;
	}
	return (NULL);
}
