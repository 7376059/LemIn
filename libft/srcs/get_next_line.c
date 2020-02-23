/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 02:32:47 by efriesen          #+#    #+#             */
/*   Updated: 2019/10/12 20:03:05 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end_of_file(char **buffer_fd, char **line, int size_buffer)
{
	int count;

	if (size_buffer == 0)
	{
		free(*buffer_fd);
		*buffer_fd = NULL;
		return (0);
	}
	if (!((*line) = (char*)malloc(sizeof(char) * size_buffer + 1)))
		return (-1);
	(*line)[size_buffer] = 0;
	count = -1;
	while ((*buffer_fd)[++count])
		(*line)[count] = (*buffer_fd)[count];
	(*buffer_fd)[0] = 0;
	return (1);
}

static int	get_line(char **buffer_fd, char **line)
{
	char	*new_buf;
	int		size_buf;
	int		size_line;

	if (!(*buffer_fd))
		return (0);
	size_line = 0;
	while (((*buffer_fd)[size_line]) && (*buffer_fd)[size_line] != '\n')
		size_line++;
	if (size_line == (size_buf = ft_strlen(*buffer_fd)))
		return (end_of_file(buffer_fd, line, size_buf));
	if (!(new_buf = (char*)malloc(sizeof(char) * (size_buf - size_line)))
			|| !((*line) = (char*)malloc(sizeof(char) * size_line + 1)))
		return (-1);
	(*line)[size_line] = 0;
	new_buf[size_buf - size_line - 1] = 0;
	size_line = -1;
	while ((*buffer_fd)[++size_line] != '\n')
		(*line)[size_line] = (*buffer_fd)[size_line];
	size_buf = 0;
	while ((*buffer_fd)[++size_line])
		new_buf[size_buf++] = (*buffer_fd)[size_line];
	free(*buffer_fd);
	*buffer_fd = new_buf;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buffer_fd[260];
	char		buf[BUFF_SIZE + 1];
	char		*available_line;
	int			count;
	int			ret;

	if ((ret = read(fd, buf, 0) == -1) || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = 0;
		if (!(available_line = (buffer_fd[fd]) ? ft_strjoin(buffer_fd[fd], buf)
					: (char*)malloc(sizeof(char) * ret + 1)))
			return (-1);
		(buffer_fd[fd]) ? free(buffer_fd[fd])
			: (available_line = ft_strcpy(available_line, buf));
		buffer_fd[fd] = available_line;
		count = 0;
		while (buf[count] && (buf[count] != '\n'))
			count++;
		if (buf[count] == '\n')
			break ;
	}
	return (get_line(&buffer_fd[fd], line));
}
