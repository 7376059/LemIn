/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_from_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:13:09 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/05 20:23:27 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mod_size_h_hh(va_list lst, char t, int base)
{
	char *str;

	if (g_param->mod_h)
	{
		if (t == 'd' || t == 'i')
			str = itoa_base_sign((short int)va_arg(lst, int), base);
		else
			str = itoa_base_unsign((unsigned short int)
					va_arg(lst, unsigned int), base);
	}
	else if (g_param->mod_hh)
	{
		if (t == 'd' || t == 'i')
			str = itoa_base_sign((signed char)va_arg(lst, int), base);
		else
			str = itoa_base_unsign((unsigned char)
					va_arg(lst, unsigned int), base);
	}
	return (str);
}

char	*mod_size_l_ll(va_list lst, char t, int base)
{
	char *str;

	if (g_param->mod_l)
	{
		if (t == 'd' || t == 'i')
			str = itoa_base_sign(va_arg(lst, long int), base);
		else
			str = itoa_base_unsign(va_arg(lst, unsigned long int), base);
	}
	else if (g_param->mod_ll)
	{
		if (t == 'd' || t == 'i')
			str = itoa_base_sign(va_arg(lst, long long int), base);
		else
			str = itoa_base_unsign(va_arg(lst, unsigned long long int), base);
	}
	return (str);
}

char	*no_mod_size(va_list lst, char t, int base)
{
	char *str;

	if (t == 'd' || t == 'i')
		str = itoa_base_sign(va_arg(lst, int), base);
	else
		str = itoa_base_unsign(va_arg(lst, unsigned int), base);
	return (str);
}
