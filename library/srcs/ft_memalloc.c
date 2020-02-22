/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:27:45 by efriesen          #+#    #+#             */
/*   Updated: 2018/12/05 14:11:04 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	if (!(mem = (unsigned char*)malloc(size)))
		return (NULL);
	if (size == 0)
		return (mem);
	while ((--size) > 0)
		mem[size] = 0;
	mem[0] = 0;
	return (mem);
}
