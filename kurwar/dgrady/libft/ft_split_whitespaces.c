/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:54:27 by dgrady            #+#    #+#             */
/*   Updated: 2019/04/28 20:12:51 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_words(char const *s)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i])
		{
			count++;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

static	char	*ft_getword(const char *s, size_t *i)
{
	char	*temp;
	size_t	j;
	size_t	start_s;
	size_t	start;

	j = 0;
	start_s = *i;
	start = 0;
	while (s[*i] != ' ' && s[*i] != '\t' && s[*i])
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

char			**ft_strsplit_whitespaces(char const *s)
{
	size_t	i;
	size_t	j;
	char	**temp;
	size_t	words;

	i = 0;
	j = 0;
	if (!(s) || !(*s))
		return (0);
	words = ft_count_words(s);
	if (!(temp = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			temp[j] = ft_getword(s, &i);
			j++;
		}
		i++;
	}
	temp[words] = 0;
	return (temp);
}
