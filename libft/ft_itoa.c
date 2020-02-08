/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:19:56 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_rev(char *a, int len, long long val)
{
	long	long	i;
	char			temp;

	i = (val < 0) ? 1 : 0;
	while (i < (len / 2))
	{
		temp = a[i];
		a[i] = a[len - i - 1];
		a[len - i - 1] = temp;
		i++;
	}
}

static	void	ft_sup(char *temp, long	long *n)
{
	if (*n < 0)
	{
		temp[0] = '-';
		*n *= -1;
	}
}

char			*ft_itoa(int n)
{
	char			*temp;
	long	long	i;
	long	long	val;

	if (!(temp = (char*)malloc(sizeof(*temp) * 13)))
		return (NULL);
	temp[12] = 0;
	if (n == 0)
	{
		temp[0] = '0';
		temp[1] = 0;
		return (temp);
	}
	i = (n < 0) ? 1 : 0;
	val = n;
	ft_sup(temp, &val);
	while (val != 0)
	{
		temp[i] = (val % 10) + 48;
		val /= 10;
		i++;
	}
	temp[i] = '\0';
	(n < 0) ? ft_rev(temp, i + 1, n) : ft_rev(temp, i, n);
	return (temp);
}
