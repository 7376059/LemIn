/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:09:59 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/09 16:48:01 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	number;
	int		count;
	int		sign;

	count = 0;
	number = 0;
	sign = 1;
	while ((9 <= str[count] && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '+' || str[count] == '-')
		if (str[count++] == '-')
			sign = -1;
	while ('0' <= str[count] && str[count] <= '9')
	{
		if (((number > 922337203685477580) || (number == 922337203685477580
						&& str[count] > '7')) && sign == 1)
			return (-1);
		if (((number > 922337203685477580) || (number == 922337203685477580
						&& str[count] > '8')) && sign == -1)
			return (0);
		number = number * 10 + (str[count++] - '0');
	}
	return (((int)number) * sign);
}
