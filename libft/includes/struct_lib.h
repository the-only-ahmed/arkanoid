/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:19:37 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:19:37 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_LIB_H
# define STRUCT_LIB_H

typedef struct		s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}					t_list;

#endif
