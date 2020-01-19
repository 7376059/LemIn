/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:18:57 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char ch;
	unsigned char tmp;

	ch = (unsigned char)c;
	if (ch > 127)
	{
		tmp = ((ch >> 6) | 0b11000000);
		write(1, &tmp, 1);
		tmp = (ch & 0b10111111);
		write(1, &tmp, 1);
	}
	else
		write(1, &ch, 1);
}
