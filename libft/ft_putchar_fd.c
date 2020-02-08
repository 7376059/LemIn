/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:41:02 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char ch;
	unsigned char tmp;

	ch = (unsigned char)c;
	if (ch > 127)
	{
		tmp = ((ch >> 6) | 0b11000000);
		write(fd, &tmp, 1);
		tmp = (ch & 0b10111111);
		write(fd, &tmp, 1);
	}
	else
		write(fd, &ch, 1);
}
