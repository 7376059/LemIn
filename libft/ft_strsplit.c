/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:36:08 by dgrady            #+#    #+#             */
/*   Updated: 2019/03/05 19:17:48 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_words(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

static	char	*ft_getword(const char *s, size_t *i, char c)
{
	char	*temp;
	size_t	j;
	size_t	start_s;
	size_t	start;

	j = 0;
	start_s = *i;
	start = 0;
	while (s[*i] != c && s[*i])
	{
		j++;
		*i = *i + 1;
	}
	(*i)--;
	if (!(temp = (char*)malloc(sizeof(*temp) * (j + 1))))
		return (NULL);
	while (j--)
	{
		temp[start] = s[start_s];
		start++;
		start_s++;
	}
	temp[start] = 0;
	return (temp);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**temp;
	size_t	words;

	i = 0;
	j = 0;
	if (!(s) || !(*s))
		return (0);
	words = ft_count_words(s, c);
	if (!(temp = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			temp[j] = ft_getword(s, &i, c);
			j++;
		}
		i++;
	}
	temp[words] = 0;
	return (temp);
}
