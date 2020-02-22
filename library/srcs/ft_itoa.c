/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:58:45 by efriesen          #+#    #+#             */
/*   Updated: 2018/12/01 02:22:39 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*str_itoa;
	int		size_number;
	long	number;

	size_number = (n <= 0) ? 1 : 0;
	number = (n < 0) ? -(long)n : n;
	while (number > 0 && ++size_number)
		number /= 10;
	if (!(str_itoa = (char*)malloc(sizeof(char) * size_number + sizeof(char))))
		return (NULL);
	str_itoa[size_number] = 0;
	str_itoa[0] = '0';
	if (n < 0)
		str_itoa[0] = '-';
	number = (n < 0) ? -(long)n : n;
	while (number > 0)
	{
		size_number--;
		str_itoa[size_number] = (number % 10) + '0';
		number = number / 10;
	}
	return (str_itoa);
}
