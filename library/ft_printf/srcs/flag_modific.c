/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_modific.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:46:06 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/06 16:48:11 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_plus_mod(char *str)
{
	char	*mod_str;
	int		length;
	int		i;

	if (str[0] == '-')
		return (str);
	length = ft_strlen(str);
	mod_str = (char*)malloc(sizeof(char) * (length + 2));
	mod_str[0] = '+';
	i = 1;
	while (i < length + 2)
	{
		mod_str[i] = str[i - 1];
		i++;
	}
	free(str);
	return (mod_str);
}

void	flag_space_mod(char *str)
{
	int	length;
	int i;

	length = ft_strlen(str);
	i = 0;
	while (i < length)
	{
		if (str[i] == '+')
			str[i] = ' ';
		i++;
	}
}

void	zero_mod_hash(char *str, int *i)
{
	if ((g_param->type == 'o' || g_param->type == 'x' || g_param->type == 'X')
			&& g_param->f_hash && !is_zero(str))
	{
		str[(*i)++] = '0';
		if (g_param->type == 'x')
			str[(*i)++] = 'x';
		else if (g_param->type == 'X')
			str[(*i)++] = 'X';
	}
}

char	*flag_zero_mod(char *str)
{
	int i;

	i = 0;
	zero_mod_hash(str, &i);
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '0';
		else if (str[i] == '-' || str[i] == '+'
				|| str[i] == '0' || str[i] == 'x' || str[i] == 'X')
		{
			if (str[i] == '-')
				str[0] = '-';
			else if (str[i] == '+')
				str[0] = '+';
			if (i > 0)
				str[i] = '0';
		}
		else
			break ;
		i++;
	}
	return (str);
}

char	*flag_hash_mod(char *str)
{
	char	*mod_str;
	int		length;
	int		i;
	int		j;

	length = ft_strlen(str);
	if (length == 0 || is_zero(str))
	{
		if (g_param->type == 'o')
			str[0] = '0';
		return (str);
	}
	if (g_param->precision == length && g_param->type == 'o' && str[0] == '0')
		return (str);
	i = (g_param->type == 'o') ? 2 : 3;
	mod_str = (char*)malloc(sizeof(char) * (length + i--));
	mod_str[0] = '0';
	mod_str[1] = (g_param->type == 'x') ? 'x' : mod_str[1];
	mod_str[1] = (g_param->type == 'X') ? 'X' : mod_str[1];
	j = -1;
	while (str[++j])
		mod_str[j + i] = str[j];
	mod_str[j + i] = '\0';
	free(str);
	return (mod_str);
}
