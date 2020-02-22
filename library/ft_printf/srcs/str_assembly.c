/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_assembly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:48:53 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/06 16:44:27 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_int(va_list lst)
{
	char *str;
	char t;

	t = g_param->type;
	if (g_param->mod_h || g_param->mod_hh)
		str = mod_size_h_hh(lst, t, get_base(t));
	else if (g_param->mod_l || g_param->mod_ll)
		str = mod_size_l_ll(lst, t, get_base(t));
	else
		str = no_mod_size(lst, t, get_base(t));
	if (g_param->precision != -1)
		str = precision_modific_int(str);
	if (g_param->f_hash && (t == 'x' || t == 'X' || t == 'o'))
		str = flag_hash_mod(str);
	if ((g_param->f_plus || g_param->f_space) && (t == 'd' || t == 'i'))
		str = flag_plus_mod(str);
	if (g_param->width != -1)
		str = width_modific(str);
	str = flag_modific_int(str);
	return (str);
}

char	*str_pointer(va_list lst)
{
	char	*str;
	char	*rez;
	int		i;

	str = itoa_base_sign(va_arg(lst, long long), 16);
	i = ft_strlen(str);
	rez = (char*)malloc(sizeof(char) * (i + 2));
	rez[0] = '0';
	rez[1] = 'x';
	if (g_param->precision == 0)
	{
		rez[3] = '\0';
		return (rez);
	}
	while (i > -1)
	{
		rez[i + 2] = str[i];
		i--;
	}
	free(str);
	if (g_param->width != -1)
		rez = width_modific(rez);
	return (rez);
}

char	*str_cs_pers(va_list lst)
{
	char	*str;

	if (g_param->type == 'c' || g_param->type == '%')
	{
		str = (char*)malloc(sizeof(char) * 2);
		if (g_param->type == 'c')
			str[0] = (char)va_arg(lst, int);
		else
			str[0] = '%';
		str[1] = 0;
	}
	else
	{
		str = va_arg(lst, char*);
		str = (!str) ? ft_strdup("(null)") : ft_strdup(str);
	}
	if (g_param->precision != -1 && g_param->type == 's')
		str = precision_modific_str(str);
	if (g_param->width != -1)
		str = width_modific(str);
	if (g_param->type == '%' && !g_param->f_minus && g_param->f_zero)
		str = flag_zero_mod(str);
	return (str);
}

char	*str_assembly(va_list lst)
{
	char *str;
	char t;

	t = g_param->type;
	if (t == 'd' || t == 'i' || t == 'o' || t == 'u' || t == 'x' || t == 'X')
		str = str_int(lst);
	else if (t == 'p')
		str = str_pointer(lst);
	else if (t == 'c' || t == 's' || t == '%')
		str = str_cs_pers(lst);
	else if (t == 'f')
		str = str_float(lst);
	return (str);
}
