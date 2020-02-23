/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:42:16 by dgrady            #+#    #+#             */
/*   Updated: 2019/10/06 16:33:23 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	get_size_float(long i)
{
	long count;

	count = 1;
	while (i /= 10)
		count++;
	return (count);
}

char	*str_rounding(char *str, double x)
{
	char	*rez;
	int		i;

	rez = round_help(str, x);
	i = ft_strlen(rez);
	i--;
	if (rez[i] < '5')
		rez[i] = 0;
	else
	{
		rez[i] = 0;
		i--;
		while (rez[i] == '9' || rez[i] == '.')
		{
			if (rez[i] == '.')
			{
				i--;
				continue;
			}
			rez[i] = '0';
			i--;
		}
		rez[i] += 1;
	}
	return (rez);
}

char	*make_it(long count, double x)
{
	int		presc;
	int		temp;
	int		i;
	char	*rez;

	i = 0;
	rez = (char*)malloc(sizeof(char*) * 20);
	while (++i < 20)
		rez[i] = 0;
	rez[0] = '.';
	presc = (g_param->precision == -1 ? 7 : g_param->precision + 1);
	x = (x < 0 ? x * (-1) : x);
	temp = (int)x;
	x = x - temp;
	i = 1;
	while (presc > 0)
	{
		x *= 10;
		temp = (int)x;
		rez[i] = temp + 48;
		x = x - temp;
		i++;
		presc--;
	}
	return (rez);
}

char	*place_minus(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i > 0)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[0] = '-';
	return (str);
}

char	*str_float(va_list lst)
{
	double	i;
	long	count;
	char	*rez;
	int		j;

	if (g_param->mod_bl == 1)
		i = va_arg(lst, long double);
	else
		i = va_arg(lst, double);
	count = get_size_float((long)i);
	rez = str_rounding(make_it(count, i), i);
	if (i < 0 && rez[0] != '-')
		rez = place_minus(rez);
	j = ft_strlen(rez);
	if (j != 0 && rez[j - 1] == '.' && !g_param->f_hash)
		rez[j - 1] = 0;
	if (g_param->f_plus || g_param->f_space)
		rez = flag_plus_mod(rez);
	if (g_param->width != -1)
		rez = width_modific(rez);
	if (g_param->f_zero && !g_param->f_minus)
		rez = flag_zero_mod(rez);
	if (g_param->f_space && !g_param->f_plus)
		flag_space_mod(rez);
	return (rez);
}
