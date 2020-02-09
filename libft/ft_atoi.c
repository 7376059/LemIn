/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:37:37 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		flag;
	long	rez;

	rez = 0;
	flag = 1;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	flag = ((*str == '-') ? -1 : 1);
	if (flag == -1 || *str == '+')
		(str++);
	while (*str > 47 && *str < 58)
		if ((rez = rez * 10 + (*(str++)) - 48) < 0)
			return (flag == 1 ? -1 : 0);
	return ((int)(rez * flag));
}
