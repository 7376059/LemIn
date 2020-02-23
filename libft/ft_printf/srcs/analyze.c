/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:07:37 by dgrady            #+#    #+#             */
/*   Updated: 2019/10/05 17:29:38 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_size(const char *str)
{
	if (g_param->type == 'f')
	{
		if ((str[0] == 'l' || str[0] == 'L') && g_param->type == 'f')
		{
			g_param->mod_l = (str[0] == 'l' ? 1 : 0);
			g_param->mod_bl = (str[0] == 'L' ? 1 : 0);
		}
		else
			return (-1);
	}
	else if (g_param->type == 'd' || g_param->type == 'i' || g_param->type ==
	'o' || g_param->type == 'u' || g_param->type == 'x' || g_param->type == 'X')
	{
		if (get_size_2(str) == -1)
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int	get_precision(const char *str)
{
	int i;

	i = 1;
	g_param->precision = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		g_param->precision = g_param->precision * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
		return (get_size(&str[i]));
	if (ft_isalpha(str[i]) == 1 || str[i] == '%')
		return (1);
	return (-1);
}

int	get_width(const char *str)
{
	int i;

	i = 0;
	g_param->width = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		g_param->width = g_param->width * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		return (get_precision(&str[i]));
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
		return (get_size(&str[i]));
	if (ft_isalpha(str[i]) == 1 || str[i] == '%')
		return (1);
	return (-1);
}

int	get_flags(const char *str)
{
	int i;

	i = -1;
	while (str[++i] == '#' || str[i] == '+' ||
			str[i] == '-' || str[i] == ' ' || str[i] == '0')
	{
		g_param->f_minus = (str[i] == '-' ? 1 : g_param->f_minus);
		if (str[i] == '+')
			g_param->f_plus = 1;
		if (str[i] == '#')
			g_param->f_hash = 1;
		if (str[i] == ' ')
			g_param->f_space = 1;
		if (str[i] == '0')
			g_param->f_zero = 1;
	}
	if (ft_isdigit(str[i]) == 1)
		return (get_width(&str[i]));
	if (str[i] == '.')
		return (get_precision(&str[i]));
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
		return (get_size(&str[i]));
	if (ft_isalpha(str[i]) == 1 || str[i] == '%')
		return (1);
	return (-1);
}

int	ft_analyze(const char *str)
{
	int i;

	i = get_type(str);
	if (i == -1)
		return (not_valid_exit(str));
	if (i == 1)
		return (i + 1);
	if (get_flags(&str[1]) == -1)
		return (not_valid_exit(str));
	return (i + 1);
}
