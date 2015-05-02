/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multistrjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:18:58 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:18:58 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_multistrjoin(size_t nb_str, ...)
{
	va_list		pa;
	char		*tmp;
	char		*str;

	if (nb_str <= 0)
		return (NULL);
	va_start(pa, nb_str);
	str = ft_strnew(0);
	while (nb_str)
	{
		tmp = str;
		str = ft_strjoin(tmp, va_arg(pa, char *));
		free(tmp);
		nb_str--;
	}
	va_end(pa);
	return (str);
}
