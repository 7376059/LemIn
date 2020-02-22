/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_modific.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:33:12 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/06 16:48:51 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision_modific_str(char *str)
{
	char	*mod_str;
	int		length;
	int		i;

	length = ft_strlen(str);
	if (g_param->precision >= length)
		return (str);
	mod_str = (char*)malloc(sizeof(char) * (g_param->precision + 1));
	i = -1;
	while (++i < g_param->precision)
		mod_str[i] = str[i];
	mod_str[i] = '\0';
	free(str);
	return (mod_str);
}

char	*width_exception_slash_zero(void)
{
	char	*mod_str;
	int		length;
	int		i;

	mod_str = (char*)malloc(sizeof(char) * (g_param->width + 1));
	i = 0;
	if (g_param->f_minus)
		mod_str[i++] = '\0';
	else
		mod_str[g_param->width - 1] = '\0';
	mod_str[g_param->width] = '\0';
	length = (g_param->f_minus) ? g_param->width : g_param->width - 1;
	while (i < length)
		mod_str[i++] = ' ';
	return (mod_str);
}

char	*width_modific(char *str)
{
	char	*mod_str;
	int		length;
	int		i;

	if (g_param->type == 'c' && !str[0])
		return (width_exception_slash_zero());
	if (g_param->width <= (length = ft_strlen(str)))
		return (str);
	i = g_param->width + 1;
	mod_str = (char*)malloc(sizeof(char) * i);
	mod_str[--i] = '\0';
	if (g_param->f_minus)
	{
		i = -1;
		while (++i < g_param->width)
			mod_str[i] = (i < length) ? str[i] : ' ';
	}
	else
	{
		while (--i >= 0)
			mod_str[i] = (--length >= 0) ? str[length] : ' ';
	}
	free(str);
	return (mod_str);
}

char	*precision_modific_int(char *str)
{
	char	*mod_str;
	int		length;
	int		i;
	int		j;

	length = ft_strlen(str);
	if (str[0] == '-')
		length--;
	if (g_param->precision == 0 && length == 1 && str[0] == '0')
	{
		str[0] = '\0';
		return (str);
	}
	if (g_param->precision <= length)
		return (str);
	i = g_param->precision + ((str[0] == '-') ? 2 : 1);
	mod_str = (char*)malloc(sizeof(char) * i);
	mod_str[0] = (str[0] == '-') ? '-' : '0';
	mod_str[--i] = '\0';
	j = (str[0] == '-') ? length : length - 1;
	while (--i > 0)
		mod_str[i] = ((str[0] != '-' && j >= 0)
				|| (str[0] == '-' && j > 0)) ? str[j--] : '0';
	free(str);
	return (mod_str);
}

char	*flag_modific_int(char *str)
{
	if (g_param->f_zero && !g_param->f_minus && (g_param->precision == -1))
		str = flag_zero_mod(str);
	if (g_param->f_space && !g_param->f_plus &&
			(g_param->type == 'd' || g_param->type == 'i'))
		flag_space_mod(str);
	return (str);
}
