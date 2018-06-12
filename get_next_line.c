/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:55:44 by amedvedi          #+#    #+#             */
/*   Updated: 2018/02/26 13:37:43 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		cut_line(char **temp, char **line, int fd)
{
	char			*tmp_temp;
	int				i;

	i = 0;
	tmp_temp = temp[fd];
	while (tmp_temp[i] != '\n')
	{
		i++;
		if (!tmp_temp[i])
		{
			free(tmp_temp);
			return (0);
		}
	}
	tmp_temp[i] = '\0';
	*line = ft_strdup(tmp_temp);
	temp[fd] = ft_strdup(tmp_temp + i + 1);
	free(tmp_temp);
	return (1);
}

static	int		read_line(char **temp, char **line, int fd)
{
	int				rd;
	char			*tmp;
	char			*buf;

	if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (!temp[fd])
			temp[fd] = ft_strdup(buf);
		else
		{
			tmp = temp[fd];
			temp[fd] = ft_strjoin(temp[fd], buf);
			free(tmp);
		}
		if (cut_line(temp, line, fd))
			break ;
	}
	free(buf);
	if (rd > 0)
		return (1);
	else
		return (rd);
}

int				get_next_line(int const fd, char **line)
{
	static char		*temp[4864];
	int				status;

	if ((fd < 0 || fd >= 4864) || !line)
		return (-1);
	if (temp[fd])
		if (cut_line(temp, line, fd))
			return (1);
	status = read_line(temp, line, fd);
	if (status != 0 || temp[fd] == NULL || temp[fd][0] == '\0')
	{
		if (status == 0 && *line)
			*line = NULL;
		return (status);
	}
	*line = temp[fd];
	temp[fd] = NULL;
	return (1);
}
