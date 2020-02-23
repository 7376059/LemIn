/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:08:55 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/06 16:48:20 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str_length_sign(long long int value, int base)
{
	long long int	value_h;
	int				str_length;

	str_length = 0;
	value_h = ((base == 10) && (value < 0)) ? -value : value;
	if (value == 0)
		str_length++;
	while (value_h > 0)
	{
		str_length++;
		value_h = value_h / base;
	}
	if ((base == 10) && (value < 0))
		str_length++;
	str_length = (str_length == 0) ? 1 : str_length;
	return (str_length);
}

char	*itoa_base_sign(long long int value, int base)
{
	long long int	value_h;
	char			*str;
	int				str_length;

	if (value == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	str_length = str_length_sign(value, base);
	str = (char*)malloc(sizeof(char) * (str_length + 1));
	str[str_length] = '\0';
	if (value == 0)
		str[0] = '0';
	value_h = ((base == 10) && (value < 0)) ? -value : value;
	if ((base == 10) && (value < 0))
		str[0] = '-';
	while (value_h > 0)
	{
		if (value_h % base < 10)
			str[--str_length] = value_h % base + '0';
		else
			str[--str_length] = (value_h % base - 10)
				+ ((g_param->type == 'X') ? 'A' : 'a');
		value_h /= base;
	}
	return (str);
}

int		str_length_unsign(unsigned long long int value, int base)
{
	unsigned long long int	value_h;
	int						str_length;

	str_length = 0;
	value_h = value;
	if (value == 0)
		str_length++;
	while (value_h > 0)
	{
		str_length++;
		value_h = value_h / base;
	}
	str_length = (str_length == 0) ? 1 : str_length;
	return (str_length);
}

char	*itoa_base_unsign(unsigned long long int value, int base)
{
	unsigned long long int	value_h;
	char					*str;
	int						str_length;

	str_length = str_length_unsign(value, base);
	str = (char*)malloc(sizeof(char) * (str_length + 1));
	str[str_length] = '\0';
	if (value == 0)
		str[0] = '0';
	value_h = value;
	while (value_h > 0)
	{
		if (value_h % base < 10)
			str[--str_length] = value_h % base + '0';
		else
			str[--str_length] = (value_h % base - 10)
				+ ((g_param->type == 'X') ? 'A' : 'a');
		value_h /= base;
	}
	return (str);
}
