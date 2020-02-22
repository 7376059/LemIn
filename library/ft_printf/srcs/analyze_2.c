/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:13:58 by dgrady            #+#    #+#             */
/*   Updated: 2019/10/05 16:18:23 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	not_valid_exit(const char *str)
{
	g_flag = 0;
	return (1);
}

int	get_type(const char *str)
{
	int i;

	i = 1;
	while (str[i] && (ft_isalpha(str[i]) == 0) && str[i] != '%')
		i++;
	if (!str[i])
		return (-1);
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
		i++;
	if (str[i] == 'l' || str[i] == 'h')
		i++;
	if (str[i] == 'c' || str[i] == 's' ||
			str[i] == 'p' || str[i] == 'd' || str[i] == 'i'
			|| str[i] == 'o' || str[i] == 'u' || str[i] == 'x' ||
			str[i] == 'X' || str[i] == 'f')
		g_param->type = str[i];
	else if (str[i] == '%')
		g_param->type = '%';
	else
		return (-1);
	return (i);
}

int	get_size_2(const char *str)
{
	if (str[0] == 'h' && str[1] == 'h')
		g_param->mod_hh = 1;
	else if (str[0] == 'h')
		g_param->mod_h = 1;
	else if (str[0] == 'l' && str[1] == 'l')
		g_param->mod_ll = 1;
	else if (str[0] == 'l')
		g_param->mod_l = 1;
	else
		return (-1);
	return (1);
}
