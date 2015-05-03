/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 19:48:29 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/02 21:23:49 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFSIZE 32
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_fd
{
	int				fd;
	char			*buf;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(int const fd, char **line);

#endif
