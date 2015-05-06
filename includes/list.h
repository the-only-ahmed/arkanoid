/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:48:32 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/03 18:58:27 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# define GLFW_INCLUDE_GLU
# include <GLFW/glfw3.h>

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_ball
{
	float			x;
	float			y;
	int			seg;
	float			dx;
	float			dy;
	float			radius;
	float			gravity;
}					t_ball;

typedef struct		s_player
{
	float			x;
	float			y;
	float			speed;
	int			size;
}					t_player;

typedef struct		s_map
{
	int				nb_l;
	int				nb_c;
	int				**map;
}					t_map;

typedef struct		s_gl
{
	int				pause;
	int				this;
	int				score;
	t_ball			ball;
	t_player			player;
	t_map				*map;
	t_vec3			scale;
	int				width;
	int				height;
	char				*titre;
	GLFWwindow		*window;
}					t_gl;

#endif
