/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsorted_trash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:39:56 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/06 16:33:52 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_zero(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] != '0' && str[i] != ' ')
			return (0);
	return (1);
}

int		get_base(char t)
{
	int base;

	if (t == 'd' || t == 'i' || t == 'u')
		base = 10;
	else if (t == 'x' || t == 'X')
		base = 16;
	else if (t == 'o')
		base = 8;
	return (base);
}

void	param_set_default(void)
{
	g_param->f_minus = 0;
	g_param->f_plus = 0;
	g_param->f_space = 0;
	g_param->f_zero = 0;
	g_param->f_hash = 0;
	g_param->precision = -1;
	g_param->width = -1;
	g_param->mod_l = 0;
	g_param->mod_ll = 0;
	g_param->mod_h = 0;
	g_param->mod_hh = 0;
	g_param->mod_bl = 0;
	g_param->type = 0;
	g_flag = 1;
}

char	*round_help(char *str, double x)
{
	char	*temp;
	char	*rez;

	temp = itoa_base_sign((long long int)x, 10);
	rez = ft_strjoin(temp, str);
	free(temp);
	free(str);
	return (rez);
}
