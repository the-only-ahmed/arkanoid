/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:53:44 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/21 19:48:35 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_fd				*init_fd(int const fd)
{
	t_fd		*tmp;

	tmp = malloc(sizeof(t_fd));
	tmp->fd = fd;
	tmp->buf = malloc(sizeof(char*) * (BUFFSIZE + 1));
	ft_bzero(tmp->buf, BUFFSIZE + 1);
	tmp->next = NULL;
	return (tmp);
}

static t_fd				*get_fd(int const fd)
{
	static t_fd		*ahmed = NULL;
	t_fd			*tmp;

	if (!ahmed)
	{
		ahmed = init_fd(fd);
		tmp = ahmed;
	}
	else
	{
		tmp = ahmed;
		while (tmp->next)
		{
			if (tmp->fd == fd)
				break ;
			tmp = tmp->next;
		}
		if (tmp->fd != fd && !tmp->next)
		{
			tmp->next = init_fd(fd);
			tmp = tmp->next;
		}
	}
	return (tmp);
}

static int				check_buffer(char *buf, char **line)
{
	char	*p;
	char	*new;
	char	*tmp;

	if ((p = ft_strchr(buf, '\n')) != NULL)
	{
		if ((new = ft_strndup(buf, p - buf)) == NULL)
			return (-1);
		buf = ft_strcpy(buf, ++p);
	}
	else
	{
		if ((new = ft_strdup(buf)) == NULL)
			return (-1);
		ft_bzero(buf, BUFFSIZE);
	}
	tmp = *line;
	if ((*line = ft_strjoin(tmp, new)) == NULL)
		return (-1);
	ft_strdel(&tmp);
	ft_strdel(&new);
	if (p != NULL)
		return (1);
	return (0);
}

int						get_next_line(int const fd, char **line)
{
	int					ret;
	t_fd				*ahmed;

	ahmed = get_fd(fd);
	if (!line || BUFFSIZE <= 0 || (*line = ft_strnew(0)) == NULL)
		return (-1);
	if (ft_strlen(ahmed->buf) != 0)
	{
		if ((ret = check_buffer(ahmed->buf, line)) != 0)
			return (ret);
	}
	while ((ret = read(fd, ahmed->buf, BUFFSIZE)) >= 0)
	{
		if (ret == 0)
		{
			if (ft_strlen(*line) > 0)
				return (1);
			ft_strdel(line);
			return (0);
		}
		ahmed->buf[ret] = '\0';
		if ((ret = check_buffer(ahmed->buf, line)) != 0)
			return (ret);
	}
	return (-1);
}
