/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:45:41 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/14 19:31:03 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	size_t	u;
	int		amount_words;

	u = 0;
	amount_words = 0;
	while (s[u])
	{
		while (s[u] && s[u] == c)
			u++;
		if (s[u])
			amount_words++;
		while (s[u] && s[u] != c)
			u++;
	}
	return (amount_words);
}

static int	ft_len(char const *s, char c, int count)
{
	int length;

	length = 0;
	while (s[count] && s[count] != c)
	{
		count++;
		length++;
	}
	return (length);
}

static char	**ft_check(char const *s, char c)
{
	char **split;

	if (!s)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*)
					* ft_words(s, c) + sizeof(char*))))
		return (NULL);
	split[ft_words(s, c)] = 0;
	return (split);
}

static char	**ft_free(char **split, int wds)
{
	while (--wds)
		free(split[wds]);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**sp;
	int		wds;
	int		count_h;

	if (!(sp = ft_check(s, c)))
		return (NULL);
	count = 0;
	wds = 0;
	while (s[count])
	{
		if (s[count] == c)
		{
			count++;
			continue ;
		}
		if (!(sp[wds] = (char*)malloc(sizeof(char) * ft_len(s, c, count) + 1)))
			return (ft_free(sp, wds));
		sp[wds][ft_len(s, c, count)] = 0;
		count_h = 0;
		while (s[count] && s[count] != c)
			sp[wds][count_h++] = s[count++];
		wds++;
	}
	return (sp);
}
