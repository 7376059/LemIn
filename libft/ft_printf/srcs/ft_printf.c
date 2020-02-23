/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:22:06 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/06 16:03:08 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		int_putstr(char *str)
{
	int i;
	int sum;

	sum = 0;
	i = 0;
	if (g_param->type == 'c')
	{
		sum += int_putchar(str[i++]);
		while (i < g_param->width)
			sum += int_putchar(str[i++]);
	}
	else
		while (str[i])
			sum += int_putchar(str[i++]);
	return (sum);
}

int		ft_printf(const char *str, ...)
{
	va_list	lst;
	char	*ret;
	int		sum;
	int		i;

	va_start(lst, str);
	g_param = (t_param*)malloc(sizeof(t_param));
	ret = NULL;
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			param_set_default();
			i += ft_analyze(&str[i]);
			sum += (g_flag) ? int_putstr(ret = str_assembly(lst)) : 0;
			free(ret);
		}
		else
			sum += int_putchar(str[i++]);
	}
	free(g_param);
	va_end(lst);
	return (sum);
}
