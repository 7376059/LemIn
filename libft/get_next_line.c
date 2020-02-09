/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:42:16 by dgrady            #+#    #+#             */
/*   Updated: 2020/01/19 13:54:55 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_line(char **str, char **line, int fd, int ret)
{
	char	*deleteme;
	size_t	len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		KEKS((*line = ft_strsub(str[fd], 0, len)));
		KEKS((deleteme = ft_strdup(str[fd] + len + 1)));
		free(str[fd]);
		str[fd] = deleteme;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		KEKS((*line = ft_strdup(str[fd])));
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*lines[10001];
	char		buf[BUFF_SIZE + 1];
	char		*deleteme;
	int			ret;

	if (fd < 0 || line == NULL || fd > 10000)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (lines[fd] == NULL)
			lines[fd] = ft_strnew(1);
		KEKS((deleteme = ft_strjoin(lines[fd], buf)));
		free(lines[fd]);
		lines[fd] = deleteme;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	SHPEKS(ret);
	if (ret == 0 && (lines[fd] == NULL || lines[fd][0] == '\0'))
		return (0);
	return (ft_get_line(lines, line, fd, ret));
}
