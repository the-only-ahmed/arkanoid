/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:18:56 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:18:56 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isspace(int c)
{
	unsigned char	val;

	val = (unsigned char)c;
	if (val == '\t' || val == '\n' || val == '\v'
		|| val == '\f' || val == '\r' || val == ' ')
		return (1);
	return (0);
}
