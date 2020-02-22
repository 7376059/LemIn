/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:28:37 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/19 18:36:28 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrstr_clr(char **arr_str)
{
	int i;

	if (arr_str == NULL)
		return ;
	i = -1;
	while (arr_str[++i])
		free(arr_str[i]);
	free(arr_str);
	arr_str = NULL;
}
